#include <stdlib.h>
#include <gst/gst.h>

    static void
abort_on_error (GError * error)
{
    if (error != NULL) g_error("error: %s", error->message);
}

    static void
wait_until_pipeline_gets_on_state(GstElement * pipeline, GstState state)
{
    GstStateChangeReturn state_change = gst_element_set_state (pipeline, state);
    if (state_change == GST_STATE_CHANGE_FAILURE) g_error("unable to change state !!!");
    g_print("waiting until state change occurs\n");
    GstState current_state = GST_STATE_NULL;
    state_change = gst_element_get_state (pipeline, &current_state, NULL, GST_CLOCK_TIME_NONE);
    if (state_change == GST_STATE_CHANGE_FAILURE) g_error("unable to get state !!!");
    g_print("done\n");
    if (current_state != state) g_error("the current state is not the expected one");
}

/* yeah we lose precision when casting the int */
static void seek_to_position_before_playing(GstElement * pipeline, guint64 start_time_in_sec)
{
    guint64 start_time = start_time_in_sec * GST_SECOND;
    wait_until_pipeline_gets_on_state(pipeline, GST_STATE_PAUSED);
    g_print("seeking to position[%llu]\n",start_time);
    if (!gst_element_seek_simple (pipeline, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH, start_time)) {
        g_error("unable to seek");
    }
    g_print("done seeking to position[%llu]\n",start_time);
}

static void log_gst_error_message(GstMessage * msg)
{
    GError * error = NULL;
    gchar * debug  = NULL;

    g_return_if_fail(msg);
    gst_message_parse_error(msg, &error, &debug);

    if (error) {
        g_print("log_gst_error_message: error[%s]\n", error->message);
        g_error_free (error);
    }

    if (debug) {
        g_print("log_gst_error_message: debug_info[%s]\n", debug);
        g_free(debug);
    }
}

int main (int argc, char * argv[])
{
    gst_init (&argc, &argv);

    if (argc < 2) {
        g_print("usage: %s <audio location> <start-time-in-sec>\n", argv[0]);
        return EXIT_SUCCESS;
    }

    GError * error = NULL;
    gchar * pipeline_description = g_strdup_printf("filesrc location=%s ! decodebin ! audioconvert ! vorbisenc ! oggmux ! filesink location=/tmp/test.ogg", argv[1]);

    g_print("building pipeline[%s]\n", pipeline_description);
    GstElement * pipeline = gst_parse_launch(pipeline_description, &error);
    g_free(pipeline_description);
    abort_on_error(error);
    g_return_val_if_fail(pipeline != NULL, EXIT_FAILURE);

    guint start_time = 0;
    if (argc >= 3) {
        start_time = atoi(argv[2]);
    }

    g_print("start in time in seconds is: %u\n", start_time);
    if (start_time != 0) {
        seek_to_position_before_playing(pipeline, start_time);
    }

    GstBus     * bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
    g_print("setting pipeline to play\n");
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    GstMessage * msg = gst_bus_poll(bus, (GstMessageType) (GST_MESSAGE_EOS | GST_MESSAGE_SEGMENT_DONE | GST_MESSAGE_ERROR), -1);
    gst_object_unref(bus);
    if (GST_MESSAGE_TYPE (msg) == GST_MESSAGE_ERROR) {
        log_gst_error_message(msg);
        return EXIT_FAILURE;
    }
    gst_element_set_state(pipeline, GST_STATE_NULL);
    return EXIT_SUCCESS;
}
