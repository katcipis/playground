/*
  Developed by Tiago Katcipis <katcipis@inf.ufsc.br>
  
  Equivalent working pipe: 

  gst-launch -v videotestsrc ! ffenc_h263p ! rtph263ppay ! udpsink host=127.0.0.1 port=5000 async=false udpsrc port=5000 caps="application/x-rtp,media=video,payload=96,clock-rate=90000,encoding-name=H263-1998" ! rtph263pdepay ! ffdec_h263 ! autovideosink pulsesrc ! audio/x-raw-int,channels=1,rate=44100 ! audioconvert ! audioresample ! alawenc ! rtppcmapay ! udpsink host=127.0.0.1 port=5001 async=false udpsrc port=5001 caps="application/x-rtp,media=audio,payload=8,clock-rate=8000,encoding-name=PCMA" ! rtppcmadepay ! alawdec ! audioconvert ! audioresample ! audio/x-raw-int,channels=1,rate=44100 ! pulsesink


*/
#include <gst/gst.h>
#include <glib.h>

#define VIDEO_PORT 5000
#define AUDIO_PORT 5001

static gboolean
bus_call (GstBus     *bus,
          GstMessage *msg,
          gpointer    data)
{
  GMainLoop *loop = (GMainLoop *) data;

  switch (GST_MESSAGE_TYPE (msg)) {

    case GST_MESSAGE_EOS:
      g_debug("End of stream");
      g_main_loop_quit (loop);
      break;

    case GST_MESSAGE_ERROR: {
      gchar  *debug;
      GError *error;

      gst_message_parse_error (msg, &error, &debug);
      g_free (debug);

      g_printerr ("Error: %s\n", error->message);
      g_error_free (error);

      g_main_loop_quit (loop);
      break;
    }
    default:
      g_debug("Msg type[%d], Msg type name[%s]", GST_MESSAGE_TYPE(msg), GST_MESSAGE_TYPE_NAME(msg));
      break;
  }

  return TRUE;
}


int
main (int   argc,
      char *argv[])
{
    GMainLoop *loop;

    GstElement *pipeline;
    /* Send video stream */
    GstElement *videosrc, *video_encoder, *rtp_video_pay, *video_udpsink;
    /* Receive video stream */
    GstElement *video_udpsrc, *rtp_video_depay, *video_decoder, *videosink;
    /* Send audio stream*/ 
    GstElement *audiosrc, *audiosrc_caps, *send_convert, *send_resample, *audio_encoder, *rtp_audio_pay, *audio_udpsink;
    /* Receive audio stream */
    GstElement *audio_udpsrc, *rtp_audio_depay, *audio_decoder, *receive_convert, *receive_resample, *audiosink_caps, *audiosink;
 
    GstBus* bus;

    /* Initialisation */
    gst_init (&argc, &argv);

    loop = g_main_loop_new (NULL, FALSE);

    if (argc < 6) {
        g_print("Usage: %s [ip_adress] [videosrc] [videosink] [audiosrc] [audiosink]\n", argv[0]);
        return 0;
    }

    /* Create gstreamer elements */
    pipeline = gst_pipeline_new ("video-conference-pipe");
    if (!pipeline) {
        g_printerr ("Error creating pipeline !!. Exiting.\n");
        return -1;
    }


    /* we add a message handler */
    bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
    gst_bus_add_watch (bus, bus_call, loop);
    gst_object_unref (bus);


    /* Set up the send video stream */
    videosrc      = gst_element_factory_make(argv[2],       NULL);
    video_encoder = gst_element_factory_make("ffenc_h263p", NULL);
    rtp_video_pay = gst_element_factory_make("rtph263ppay", NULL);
    video_udpsink = gst_element_factory_make("udpsink",     NULL);   

    if (!videosrc || !video_encoder || !rtp_video_pay || !video_udpsink) {
        g_printerr ("Error creating send video stream !!! Exiting.\n");
        return -1;
    } 
 
    gst_bin_add_many (GST_BIN (pipeline),
                      videosrc, video_encoder, rtp_video_pay, video_udpsink, NULL);

    if (! gst_element_link_many (videosrc, video_encoder, rtp_video_pay, video_udpsink, NULL)) {
        g_printerr ("Error linking send video stream !!. Exiting.\n");
        return -1;
    }
    
    g_object_set (G_OBJECT (video_udpsink), "port", VIDEO_PORT, NULL);
    g_object_set (G_OBJECT (video_udpsink), "host", argv[1],    NULL);
    g_object_set (G_OBJECT (video_udpsink), "async", FALSE,     NULL);
    /* End of the send video stream set up*/


    /* Set up the receive video stream */
    video_udpsrc    = gst_element_factory_make("udpsrc",        NULL);
    rtp_video_depay = gst_element_factory_make("rtph263pdepay", NULL);
    video_decoder   = gst_element_factory_make("ffdec_h263"   , NULL);
    videosink       = gst_element_factory_make(argv[3]        , NULL);

    if (!video_udpsrc || !rtp_video_depay || !video_decoder || !videosink) {
        g_printerr ("Error creating receive video stream !!! Exiting.\n");
        return -1;
    }

    gst_bin_add_many (GST_BIN (pipeline),
                      video_udpsrc, rtp_video_depay, video_decoder, videosink, NULL);

    if (! gst_element_link_many (video_udpsrc, rtp_video_depay, video_decoder, videosink, NULL)) {
        g_printerr ("Error linking send video stream !!. Exiting.\n");
        return -1;
    }

    g_object_set (G_OBJECT (video_udpsrc), "port", VIDEO_PORT, NULL);
    g_object_set (G_OBJECT (video_udpsrc), "caps", gst_caps_from_string("application/x-rtp,media=video,payload=96,clock-rate=90000,encoding-name=H263-1998"),    NULL);
    /* End of the receive video stream set up*/


    /* Set up the send audio stream */
    audiosrc      =  gst_element_factory_make(argv[4], NULL);
    audiosrc_caps =  gst_element_factory_make("capsfilter",    NULL); 
    send_convert  =  gst_element_factory_make("audioconvert" , NULL);
    send_resample =  gst_element_factory_make("audioresample", NULL);
    audio_encoder =  gst_element_factory_make("alawenc"      , NULL);
    rtp_audio_pay =  gst_element_factory_make("rtppcmapay"   , NULL);
    audio_udpsink =  gst_element_factory_make("udpsink"      , NULL);

    if (!audiosrc || !audiosrc_caps || !send_convert || !send_resample || !audio_encoder || !rtp_audio_pay || !audio_udpsink) {
        g_printerr ("Error creating send audio stream !!! Exiting.\n");
        return -1;
    } 
 
    gst_bin_add_many (GST_BIN (pipeline),
                      audiosrc, audiosrc_caps, send_convert, send_resample, audio_encoder, rtp_audio_pay, audio_udpsink, NULL);

    if (! gst_element_link_many (audiosrc, audiosrc_caps, send_convert, send_resample, audio_encoder, rtp_audio_pay, audio_udpsink, NULL)) {
        g_printerr ("Error linking send audio stream !!. Exiting.\n");
        return -1;
    }
    
    g_object_set (G_OBJECT (audio_udpsink), "port", AUDIO_PORT, NULL);
    g_object_set (G_OBJECT (audio_udpsink), "host", argv[1],    NULL);
    g_object_set (G_OBJECT (audio_udpsink), "async", FALSE,     NULL);
    g_object_set (G_OBJECT (audiosrc_caps), "caps",  gst_caps_from_string("audio/x-raw-int,channels=1,rate=44100"), NULL);
    /* End of the send audio stream set up*/


    /* Set up the receive audio stream */
    audio_udpsrc     = gst_element_factory_make("udpsrc"       , NULL);
    rtp_audio_depay  = gst_element_factory_make("rtppcmadepay" , NULL);
    audio_decoder    = gst_element_factory_make("alawdec"      , NULL);     
    receive_convert  = gst_element_factory_make("audioconvert" , NULL);
    receive_resample = gst_element_factory_make("audioresample", NULL);
    audiosink_caps   = gst_element_factory_make("capsfilter",    NULL);
    audiosink        = gst_element_factory_make(argv[5]        , NULL);

    if (!audio_udpsrc || !rtp_audio_depay || !audio_decoder || !receive_convert || !receive_resample || !audiosink_caps || !audiosink) {
        g_printerr ("Error creating receive audio stream !!! Exiting.\n");
        return -1;
    } 
 
    gst_bin_add_many (GST_BIN (pipeline),
                      audio_udpsrc, rtp_audio_depay, audio_decoder, receive_convert, receive_resample, audiosink_caps, audiosink, NULL);

    if (! gst_element_link_many (audio_udpsrc, rtp_audio_depay, audio_decoder, receive_convert, receive_resample, audiosink_caps, audiosink, NULL)) {
        g_printerr ("Error linking receive audio stream !!. Exiting.\n");
        return -1;
    }

    g_object_set (G_OBJECT (audio_udpsrc),   "port", AUDIO_PORT, NULL);
    g_object_set (G_OBJECT (audio_udpsrc),   "caps", gst_caps_from_string("application/x-rtp,media=audio,payload=8,clock-rate=8000,encoding-name=PCMA"), NULL);
    g_object_set (G_OBJECT (audiosink_caps), "caps", gst_caps_from_string("audio/x-raw-int,channels=1,rate=44100"), NULL);
    /* End of the receive audio stream set up*/    


    /* Set the pipeline to "playing" state*/
    gst_element_set_state (pipeline, GST_STATE_PLAYING);

    /* Iterate */
    g_print ("Running...\n");
    g_main_loop_run (loop);

    /* Out of the main loop, clean up nicely */
    g_print ("setting pipeline to NULL !\n");
    gst_element_set_state (pipeline, GST_STATE_NULL);

    g_print ("Deleting pipeline\n");
    gst_object_unref (GST_OBJECT (pipeline));

    return 0;
}

