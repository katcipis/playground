#include <gst/gst.h>

static gint64 seg_start    = 0;
static gint64 seg_end      = 0;
static GstElement* pipeline = NULL;

static const char* get_name_state(GstState state)
{
    if (GST_STATE_VOID_PENDING == state)
        return "GST_STATE_VOID_PENDING";
    if (GST_STATE_NULL == state)
        return "GST_STATE_NULL";
    if (GST_STATE_READY == state)
        return "GST_STATE_READY";
    if (GST_STATE_PAUSED == state)
        return "GST_STATE_PAUSED";
    if (GST_STATE_PLAYING == state)
        return "GST_STATE_PLAYING";

    return "UNKNOW_STATE!!!!";
}

static const char* get_state_change_name(GstStateChangeReturn state)
{
    if (GST_STATE_CHANGE_FAILURE == state)
        return "GST_STATE_CHANGE_FAILURE";
    if (GST_STATE_CHANGE_SUCCESS == state)
        return "GST_STATE_CHANGE_SUCCESS";
    if (GST_STATE_CHANGE_ASYNC == state)
        return "GST_STATE_CHANGE_ASYNC";
    if (GST_STATE_CHANGE_NO_PREROLL == state)
        return "GST_STATE_CHANGE_NO_PREROLL";

    return "UNEXPECTED_STATE_CHANGE";
}


static void do_first_seek()
{
   GstStateChangeReturn ret;
   GstState state;
   GstState pending;

   g_print("do_first_seek: setting pipe to paused !!\n");
   gst_element_set_state (pipeline, GST_STATE_PAUSED);
   g_print("do_first_seek: waiting to complete pause change\n");
   ret = gst_element_get_state(pipeline, &state, &pending, 10 * GST_SECOND);
   g_print("do_first_seek: achieved state[%s] pending[%s] state_change[%s]\n", get_name_state(state),
                                                                               get_name_state(pending),
                                                                               get_state_change_name(ret));
   
   if (ret != GST_STATE_CHANGE_SUCCESS) {
       g_warning("ERROR!!!, could not get to paused state !!!");
       return;
   }

   if(!gst_element_seek (pipeline,
                           1.0,
                           GST_FORMAT_TIME,
                           GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_SEGMENT | GST_SEEK_FLAG_ACCURATE,
                           GST_SEEK_TYPE_SET,
                           seg_start,
                           GST_SEEK_TYPE_SET,
                           seg_end)){
        g_print("do_first_seek: Erro fazendo loop\n");
        return;
    }

    g_print("do_first_seek: segment seek done, start[%lli] end[%lli]\n", seg_start, seg_end);
    gst_element_set_state (pipeline, GST_STATE_PLAYING);
}

static void do_seek_segment()
{
   if(!gst_element_seek (pipeline,
                           1.0,
                           GST_FORMAT_TIME,
                           GST_SEEK_FLAG_SEGMENT | GST_SEEK_FLAG_ACCURATE,
                           GST_SEEK_TYPE_SET,
                           seg_start,
                           GST_SEEK_TYPE_SET,
                           seg_end)){
        g_print("do_seek_segment: Erro fazendo loop\n");
        return;
    }
    
    g_print("do_seek_segment: segment seek done, start[%lli] end[%lli]\n", seg_start, seg_end);
}


static gboolean bus_call (GstBus *bus, GstMessage *msg, gpointer data)
{
    GMainLoop *loop = (GMainLoop *) data;

    switch (GST_MESSAGE_TYPE (msg))
    {
        case GST_MESSAGE_STATE_CHANGED : {
            GstState oldstate;
            GstState newstate;
            GstState pending;

            gst_message_parse_state_changed (msg, &oldstate, &newstate, &pending);

            g_print("state old:%s => new:%s pending(%s)\n",
                    get_name_state(oldstate),
                    get_name_state(newstate),
                    get_name_state(pending));

        } break;

        case GST_MESSAGE_SEGMENT_DONE: {
            GstStateChangeReturn ret;
            GstState state;
            GstState pending;
            
            ret = gst_element_get_state(pipeline, &state, &pending, 2 * GST_SECOND);
            g_print("segment done !!! state[%s] pending[%s] state_change[%s]\n", get_name_state(state), 
                                                                                 get_name_state(pending),
                                                                                 get_state_change_name(ret));

            if (state == GST_STATE_PAUSED) {
                g_print("CANT SEEK, LOCKED ON PAUSED STATE !!!\n");
            } else {
                do_seek_segment();
            }
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
    GMainLoop *loop      = NULL;
    GstBus *bus          = NULL;
    GstElement *identity = NULL; 

    gst_init (&argc,&argv);

    loop = g_main_loop_new (NULL, FALSE);

    if (argc < 4) {
        g_print ("usage: %s <gst-launch-like pipeline> <seg_start_ms> <seg_end_ms> [<optional_identity_name>]\n", argv[0]);
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

    seg_start = atoi(argv[2]) * GST_MSECOND;
    seg_end   = atoi(argv[3]) * GST_MSECOND;
    
    g_debug("SEG_START[%lli]", seg_start);
    g_debug("SENG_END[%lli]",  seg_end);

    /* Creating optional identity debug element */
    if (argc == 5) {
        g_debug("Getting identity element with name=%s", argv[4]);
        identity = gst_bin_get_by_name (GST_BIN(pipeline), argv[4]);
        if (identity) {
            g_signal_connect (identity, "handoff",  G_CALLBACK(handle_handoff), NULL);
            gst_object_unref (GST_OBJECT (identity));
        } else {
            g_warning("ERROR IDENTITY NOT FOUND ON PIPELINE !!!");
        }
    } 

    /* lets set it to play but first set it to play the right segment */
    do_first_seek();

    /* Iterate */
    g_print ("Running...\n");
    g_main_loop_run (loop);

    /* Out of the main loop, clean up nicely */
    g_print ("Terminating...\n");
    gst_element_set_state (pipeline, GST_STATE_NULL);

    g_print ("Deleting pipeline...\n");
    gst_object_unref (GST_OBJECT (pipeline));

    exit (0);
}

