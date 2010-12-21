#include <gst/gst.h>

#define SEEK_TIMEOUT   15
#define DELETE_TIMEOUT 30

static GstElement* pipeline = NULL;
static GMainLoop *loop      = NULL;

static gboolean destroy_pipe(gpointer p)
{
    GstStateChangeReturn null_ret;

    g_debug("destroy_pipe: calling gst_element_set_state, setting to NULL !!!");
    null_ret = gst_element_set_state (pipeline, GST_STATE_NULL);
    g_debug("destroy_pipe: calling gst_element_set_state returned[%s] !!!",
            gst_element_state_change_return_get_name(null_ret));

    g_debug("destroy_pipe: calling gst_object_unref");
    gst_object_unref (GST_OBJECT (pipeline));
    g_debug("destroy_pipe: gst_object_unref returned !!!");

    g_main_loop_quit (loop);

    return FALSE;
}


static gboolean seek_pipe(gpointer p)
{
    gboolean ret;

    g_debug("seek_pipe: calling gst_element_seek !!!");

    ret = gst_element_seek (pipeline, 1.0, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_KEY_UNIT,
                            GST_SEEK_TYPE_SET, 1 * GST_SECOND, GST_SEEK_TYPE_NONE, 0);

    g_debug("seek_pipe: gst_element_seek returned[%d] !!!", ret);
    return FALSE;
}


static gboolean bus_call (GstBus *bus, GstMessage *msg, gpointer data)
{

    switch (GST_MESSAGE_TYPE (msg))
    {
        case GST_MESSAGE_STATE_CHANGED : {
            GstState oldstate;
            GstState newstate;
            GstState pending;

            gst_message_parse_state_changed (msg, &oldstate, &newstate, &pending);

            g_print("state old:%s => new:%s pending(%s)\n",
                    gst_element_state_get_name(oldstate),
                    gst_element_state_get_name(newstate),
                    gst_element_state_get_name(pending));

        } break;

        case GST_MESSAGE_EOS:
        {
            g_print ("Fim da stream\n");
            g_main_loop_quit (loop);
            break;
        }

        case GST_MESSAGE_ERROR:
        {
            gchar  *debug;
            GError *error;

            gst_message_parse_error (msg, &error, &debug);
            g_free (debug);

            g_printerr ("Erro: %s\n", error->message);
            g_error_free (error);

            g_main_loop_quit (loop);
            break;
        }

        default:
            break;
        }

    return TRUE;
}


static void handle_handoff(GstElement *identity, GstBuffer *buffer,  gpointer user_data)
{
    g_debug("HANDOFF SIGNAL : TIMESTAMP[%lld], DURATION[%lld], SIZE[%d]", GST_BUFFER_TIMESTAMP(buffer),
                                                                          GST_BUFFER_DURATION(buffer),
                                                                          GST_BUFFER_SIZE(buffer));
}


int 
main (int argc, char *argv[]) 
{
    GError *error        = NULL;
    GstBus *bus          = NULL;
    GstElement *identity = NULL; 
    GstStateChangeReturn play_ret;

    gst_init (&argc,&argv);

    loop = g_main_loop_new (NULL, FALSE);

    if (argc < 2) {
        g_print ("usage: %s <gst-launch-like pipeline> [<optional_identity_name>]\n", argv[0]);
        exit (-1);
    }

    pipeline = gst_parse_launch(argv[1], &error);

    if (error) {
        g_warning("Warning [%s]", error->message);
    }
  
    if(!pipeline){
        g_warning("Error building pipeline [%s]", argv[1]);
        exit (-1);
    }

    bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
    gst_bus_add_watch (bus, bus_call, loop);
    gst_object_unref (bus);

    
    /* Creating optional identity debug element */
    if (argc == 3) {
        g_debug("Getting identity element with name=%s", argv[2]);
        identity = gst_bin_get_by_name (GST_BIN(pipeline), argv[2]);
        if (identity) {
            g_signal_connect (identity, "handoff",  G_CALLBACK(handle_handoff), NULL);
            gst_object_unref (GST_OBJECT (identity));
        } else {
            g_warning("ERROR IDENTITY NOT FOUND ON PIPELINE !!!");
        }
    } 


    g_debug("Setting pipe to PLAY !!");
    play_ret = gst_element_set_state (pipeline, GST_STATE_PLAYING);
    g_debug("Set to play returned [%s]!!!", gst_element_state_change_return_get_name(play_ret));

    g_debug("Starting timer to seek pipeline, will seek in [%d] seconds!!!", SEEK_TIMEOUT);
    g_timeout_add_seconds(SEEK_TIMEOUT, seek_pipe, NULL);

    g_debug("Starting timer to set pipeline to NULL, will set to null in [%d] seconds!!!", DELETE_TIMEOUT);
    g_timeout_add_seconds(DELETE_TIMEOUT, destroy_pipe, NULL);

    /* Iterate */
    g_print ("Running...\n");
    g_main_loop_run (loop);

    exit (0);
}

