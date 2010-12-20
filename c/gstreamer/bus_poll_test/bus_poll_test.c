#include <gst/gst.h>

static void handle_handoff(GstElement *identity, GstBuffer *buffer,  gpointer user_data)
{
    g_debug("HANDOFF SIGNAL : TIMESTAMP[%lld], DURATION[%lld], SIZE[%d]", GST_BUFFER_TIMESTAMP(buffer),
                                                                          GST_BUFFER_DURATION(buffer),
                                                                          GST_BUFFER_SIZE(buffer));
}


int 
main (int argc, char *argv[]) 
{
    GError *error         = NULL;
    GstBus *bus           = NULL;
    GstElement *identity  = NULL; 
    GstStateChangeReturn play_ret;
    GstMessage * msg      = NULL;
    GstElement * pipeline = NULL;

    gst_init (&argc,&argv);

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

    g_print ("Polling...\n");

    bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));

    msg = gst_bus_poll(bus, GST_MESSAGE_EOS | GST_MESSAGE_ERROR, -1);

    if (GST_MESSAGE_TYPE (msg) == GST_MESSAGE_ERROR) {
        gchar  *debug;
        GError *error;

        gst_message_parse_error (msg, &error, &debug);
        g_free (debug);

        g_printerr ("Erro: %s\n", error->message);
        g_error_free (error);
    } else {
        g_print ("Fim da stream\n");
    }

    gst_object_unref (bus);
    exit (0);
}

