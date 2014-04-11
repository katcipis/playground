#include <stdio.h>
#include <stdlib.h>
#include <gst/gst.h>
#include <gio/gio.h>

#define VORBIS_CBR 32000
#define VORBIS_CBR_STR "32000"

static gchar * protocol = NULL;
static gchar * address = NULL;
static gchar * file_location = NULL;
static gchar * login = NULL;
static gchar * password = NULL;


static GOptionEntry entries[] =
{
  { "protocol", 'p', 0, G_OPTION_ARG_STRING, &protocol, "protocol to be used to access the storage of the media file", "ssh" },
  { "address", 'a', 0, G_OPTION_ARG_STRING, &address, "ip address of the storage of the media file", "127.0.0.1" },
  { "file-location", 'f', 0, G_OPTION_ARG_STRING, &file_location, "media file location on the storage", "/tmp/file.wav" },
  { "login", 'l', 0, G_OPTION_ARG_STRING, &login, "login to be used to access the storage (optional)", "userlogin" },
  { "password", 'P', 0, G_OPTION_ARG_STRING, &password, "password to be used to access the storage (optional)", "userpassword" },
  { NULL }
};

static void
start_streamer(void);

static void
log_gst_error_message(GstMessage * msg)
{
    GError * error = NULL;
    gchar * dbg_info = NULL;
    gst_message_parse_error (msg, &error, &dbg_info);
    g_printerr ("ERROR: element %s: detail: %s\n", GST_OBJECT_NAME (msg->src), error->message);
    g_printerr ("Debugging info: %s\n", (dbg_info) ? dbg_info : "none");
    g_error_free (error);
    g_free (dbg_info);
    gst_message_unref(msg);
}

static void
log_gst_warning_message(GstMessage * msg)
{
    GError * error = NULL;
    gchar * dbg_info = NULL;
    gst_message_parse_warning (msg, &error, &dbg_info);
    g_printerr ("WARNING: element %s: detail: %s\n", GST_OBJECT_NAME (msg->src), error->message);
    g_printerr ("Debugging info: %s\n", (dbg_info) ? dbg_info : "none");
    g_error_free (error);
    g_free (dbg_info);
    gst_message_unref(msg);
}

static void
abort_on_error (GError * error)
{
    if (error != NULL) g_error("error: %s", error->message);
}

static gboolean
is_a_not_mounted_gst_message(GstMessage * msg)
{
    return GST_MESSAGE_TYPE(msg) == GST_MESSAGE_ELEMENT &&
           gst_message_has_name(msg, "not-mounted");
}

static GFile *
get_gfile_to_mount (GstElement * pipeline)
{
    /* 
     * For details see: 
     * http://gstreamer.freedesktop.org/data/doc/gstreamer/head/gst-plugins-base-plugins/html/gst-plugins-base-plugins-giosrc.html 
     */
    GstBus * bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
    GstMessage * msg = NULL;
    while ((msg = gst_bus_pop (bus))) {
        if (GST_MESSAGE_TYPE(msg) == GST_MESSAGE_ERROR) {
            log_gst_error_message(msg);
            continue;
        }
        if (GST_MESSAGE_TYPE(msg) == GST_MESSAGE_WARNING) {
            log_gst_warning_message(msg);
            continue;
        }
        if (is_a_not_mounted_gst_message(msg)) {
            const GstStructure * msg_struct = gst_message_get_structure (msg);
            if (msg_struct == NULL) {
                g_error("unable to get message struct from 'not-mounted' message !!!");
            }
            GFile *file = G_FILE (g_value_dup_object(gst_structure_get_value (msg_struct, "file")));
            if (file == NULL) {
                g_error("unable to get GFile* from the message struct, cant do mount operation");
            }
            gst_object_unref(bus);
            gst_message_unref(msg);
            return file;
        }
        gst_message_unref(msg);
    }
    gst_object_unref(bus);
    g_error("unable to find 'not-mounted' error, pipeline has given another error !!!");
}

static void 
on_password_asked (GMountOperation *operation, 
                   gchar *message, 
                   gchar *default_user, 
                   gchar *default_domain, 
                   GAskPasswordFlags flags, 
                   gpointer userdata)
{
    if (password == NULL) {
        g_error("mount operation requires a password but no one has been given");
    }
    g_mount_operation_set_password(operation, password);
    g_mount_operation_reply (operation, G_MOUNT_OPERATION_HANDLED);
}

static void on_mount_operation_completed (GObject *object,
                                          GAsyncResult *res,
                                          gpointer userdata)
{
    GError *error = NULL;

    if (!g_file_mount_enclosing_volume_finish (G_FILE (object), res, &error)) {
       static const gint GIO_MOUNT_ALREADY_MOUNTED_CODE = 17;
       static const gint GIO_MOUNT_POINT_ALREADY_REGISTERED = 0;
       if (error->code != GIO_MOUNT_ALREADY_MOUNTED_CODE &&
           error->code != GIO_MOUNT_POINT_ALREADY_REGISTERED) {
            if (error) {
               g_error("error[%s]: doing mount operation: gio mount code[%i]", error->message, error->code);
            }
            g_error("error on mount operation without any details");
        } 
    }
    GMainLoop * loop = (GMainLoop *) userdata;
    g_main_loop_quit(loop);
}

static void
mount_remote_location (GstElement * pipeline)
{
    GFile * file = get_gfile_to_mount(pipeline);
    GMountOperation *operation = g_mount_operation_new ();
    g_signal_connect (operation, "ask_password", G_CALLBACK (on_password_asked), NULL);
    GMainLoop * loop = g_main_loop_new(NULL, FALSE);
    g_file_mount_enclosing_volume (file, G_MOUNT_MOUNT_NONE, operation,
                                   NULL, on_mount_operation_completed, loop);
    g_main_loop_run(loop);

    g_main_loop_unref(loop);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    g_object_unref(operation);
    /* we have mounted the location with success, lets do it all again */
    start_streamer();
}

static gboolean
set_pipeline_state(GstElement * pipeline, GstState state)
{
    GstStateChangeReturn state_change = gst_element_set_state (pipeline, state);
    if (state_change == GST_STATE_CHANGE_FAILURE) {
        mount_remote_location(pipeline);
        return FALSE; 
    }
    GstState current_state = GST_STATE_NULL;
    state_change = gst_element_get_state (pipeline, &current_state, NULL, GST_CLOCK_TIME_NONE);
    if (state_change == GST_STATE_CHANGE_FAILURE) g_error("unable to get state !!!");
    if (current_state != state) g_error("the current state is not the expected one");
    return TRUE;
}

static gint64
predict_ogg_vorbis_file_size_in_bytes (gint64 original_file_duration)
{
    gint64 duration_in_sec = GST_TIME_AS_SECONDS(original_file_duration);
    g_printerr("duration is sec: %lli\n", duration_in_sec);
    g_printerr("duration is ms: %lli\n", GST_TIME_AS_MSECONDS(original_file_duration));
    g_printerr("original duration: %lli\n", original_file_duration);
    /* TODO: FIXME: Getting the size of stream in bytes is not working propertly */
    return ((VORBIS_CBR * duration_in_sec) / 8) * 3;
}

static gboolean
send_media_information(GstElement * pipeline)
{
    if (!set_pipeline_state(pipeline, GST_STATE_PAUSED)) {
        return FALSE;
    }

    gint64 time_duration = 0;
    if (!gst_element_query_duration (pipeline, GST_FORMAT_TIME, &time_duration)) {
        g_error("unable to get duration information from the pipeline, cant go on");
    }

    fprintf(stdout, "{\"len\":%llu,\"duration\":%lli}\n", 
            predict_ogg_vorbis_file_size_in_bytes(time_duration), time_duration);
    fflush(stdout);
    getchar();
    return TRUE;
}

static GstElement *
build_ogg_vorbis_pipeline(void)
{
    /* audioparse is required to make IMA ADPCM work properly */
    /* TODO: TEST WHEN THERE IS NO LOGIN !!! */
    GError * error = NULL;
    gchar * pipeline_description = 
        g_strdup_printf("giosrc location=%s://%s@%s%s ! decodebin ! audioconvert ! audioresample"
                        " ! audioparse rate=8000 channels=1 ! audioconvert "
                        " ! vorbisenc managed=true min-bitrate="VORBIS_CBR_STR" max-bitrate="VORBIS_CBR_STR" bitrate="VORBIS_CBR_STR
                        " ! oggmux ! fdsink", protocol, login, address, file_location);
    GstElement * pipeline = gst_parse_launch(pipeline_description, &error);
    g_free(pipeline_description);
    abort_on_error(error);
    return pipeline;
    return NULL;
}

static void
start_streamer(void)
{
    GstElement * pipeline =  build_ogg_vorbis_pipeline();
    if (!send_media_information(pipeline)) {
        return;
    }
    GstBus * bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    GstMessage * msg = gst_bus_poll(bus, (GstMessageType) (GST_MESSAGE_EOS | GST_MESSAGE_SEGMENT_DONE | GST_MESSAGE_ERROR), -1);
    gst_object_unref(bus);
    if (GST_MESSAGE_TYPE (msg) == GST_MESSAGE_ERROR) {
        log_gst_error_message(msg);
    }
    gst_element_set_state(pipeline, GST_STATE_NULL);
}

int main (int argc, char * argv[])
{
    gst_init (&argc, &argv);
    GOptionContext * context = g_option_context_new ("- media streamer");
    GError * error = NULL;
    g_option_context_add_main_entries (context, entries, NULL);
    if (!g_option_context_parse (context, &argc, &argv, &error)) {
        abort_on_error(error);
        return EXIT_FAILURE;
    }
    abort_on_error(error);
    if (file_location == NULL || protocol == NULL || address == NULL) {
        g_error("Invalid parameters informed: file_location[%s] protocol[%s] address[%s]", 
                 file_location, protocol, address);
    }
    start_streamer();
    return EXIT_SUCCESS;
}
