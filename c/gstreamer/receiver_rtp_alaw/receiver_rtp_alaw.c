/*
  Developed by Tiago Katcipis <katcipis@inf.ufsc.br>
  Equivalent working pipe: gst-launch -v udpsrc port=5000 caps="application/x-rtp,media=audio,payload=8,clock-rate=8000,encoding-name=PCMA" ! .recv_rtp_sink_0 gstrtpbin ! rtppcmadepay ! alawdec ! pulsesink

  To test this source code use the following pipe: gst-launch -v gstrtpbin name=rtpbin audiotestsrc ! alawenc ! rtppcmapay ! rtpbin.send_rtp_sink_0 rtpbin.send_rtp_src_0 ! identity ! udpsink port=5000 host=127.0.0.1

*/

#include <gst/gst.h>
#include <glib.h>

#define UDP_RECEIVE_PORT 5000

static gboolean
bus_call (GstBus     *bus,
          GstMessage *msg,
          gpointer    data)
{
  GMainLoop *loop = (GMainLoop *) data;

  switch (GST_MESSAGE_TYPE (msg)) {

    case GST_MESSAGE_EOS:
      g_print ("End of stream\n");
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
      g_print("Msg type[%d], Msg type name[%s]\n", GST_MESSAGE_TYPE(msg), GST_MESSAGE_TYPE_NAME(msg));
      break;
  }

  return TRUE;
}


static void
on_pad_added (GstElement *element,
              GstPad     *pad,
              gpointer    data)
{
  GstPad *sinkpad;
  GstElement *rtp_alaw_depay = (GstElement *) data;

  /* We can now link this pad with the rtpdepay sink pad */
  g_print ("on_pad_added: Dynamic pad created, linking demuxer/decoder\n");
  sinkpad = gst_element_get_static_pad (rtp_alaw_depay, "sink");

  if(gst_pad_link (pad, sinkpad) != GST_PAD_LINK_OK){
      g_warning("on_pad_added: Error linking src pad from gstrtpbin to sink pad from rtp_alaw_depay");
  }
  gst_object_unref (sinkpad);
}

static void
on_new_ssrc (GstElement *element,
              guint      session,
              guint      ssrc,
              gpointer   data)
{
    g_debug("New SSRC established, session[%d], ssrc[%u]", session, ssrc);
}

int
main (int   argc,
      char *argv[])
{
  GMainLoop *loop;

  GstElement* pipeline, *source, *gstrtpbin, *rtp_alaw_depay, *alawdec, *sink;
  GstBus* bus;
  GstPad* recv_rtp_sink;

  /* Initialisation */
  gst_init (&argc, &argv);

  loop = g_main_loop_new (NULL, FALSE);

  /* Create gstreamer elements */
  pipeline      = gst_pipeline_new ("rtp-raw-stream-player");
  source        = gst_element_factory_make ("udpsrc",  "udp-source");
  gstrtpbin     = gst_element_factory_make ("gstrtpbin",  "gst-rtpbin");
  rtp_alaw_depay = gst_element_factory_make ("rtppcmadepay",  "rtp_pcma_depay");
  alawdec        = gst_element_factory_make ("alawdec", "alaw-decoder");
  sink          = gst_element_factory_make ("pulsesink", "audio-output");
  

  if (!pipeline || !source || !gstrtpbin || !rtp_alaw_depay || !alawdec || !sink) {
      g_printerr ("One element could not be created. Exiting.\n");
      return -1;
  }

  /* Set up the pipeline */
  g_debug("Teste");

  /* we set the input filename to the source element */
  g_object_set (G_OBJECT (source), "port", UDP_RECEIVE_PORT, NULL);
  g_debug("Teste");
  g_object_set (G_OBJECT (source), "caps", gst_caps_from_string("application/x-rtp,media=audio,payload=8,clock-rate=8000,encoding-name=PCMA"), NULL);

  g_debug("Teste");
  /* we add a message handler */
  bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
  gst_bus_add_watch (bus, bus_call, loop);
  gst_object_unref (bus);

  /* we add all elements into the pipeline */
  gst_bin_add_many (GST_BIN (pipeline),
                    source, gstrtpbin, rtp_alaw_depay, alawdec, sink, NULL);

  recv_rtp_sink = gst_element_get_request_pad(gstrtpbin, "recv_rtp_sink_0");
  if(!recv_rtp_sink){
      g_warning("Error getting recv_rtp_sink_0");
      g_print ("Deleting pipeline\n");
      gst_object_unref (GST_OBJECT (pipeline));
      return -1;
  }

  /* we link the elements together */
  if(gst_pad_link(gst_element_get_static_pad(source, "src"), recv_rtp_sink) != GST_PAD_LINK_OK){
      g_warning("Error linking src to recv_rtp_sink");
      g_print ("Deleting pipeline\n");
      gst_object_unref (GST_OBJECT (pipeline));
      return -1;
  }
  
  if(!gst_element_link (rtp_alaw_depay, alawdec)){
      g_warning("Error linking rtp_alaw_depay to alawdec");
      g_print ("Deleting pipeline\n");
      gst_object_unref (GST_OBJECT (pipeline));
      return -1;
  }

  if(!gst_element_link (alawdec, sink)){
      g_warning("Error linking rtp_alaw_dec to sink");
      g_print ("Deleting pipeline\n");
      gst_object_unref (GST_OBJECT (pipeline));
      return -1;
  }

  /*
    Each RTP stream is demuxed based on the SSRC and send to a GstRtpJitterBuffer. After the packets are released from the jitterbuffer, they will be forwarded to a 
    GstRtpsSrcDemux element. The GstRtpsSrcDemux element will demux the packets based on the payload type and will create a unique pad recv_rtp_src_%d_%d_%d on gstrtpbin 
    with the session number, SSRC and payload type respectively as the pad name. 
  */
  g_signal_connect (gstrtpbin, "pad-added",   G_CALLBACK (on_pad_added), rtp_alaw_depay);
  g_signal_connect (gstrtpbin, "on-new-ssrc", G_CALLBACK (on_new_ssrc), NULL);

  /* Set the pipeline to "playing" state*/
  g_print ("Now listening on port: %d\n", UDP_RECEIVE_PORT);
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Iterate */
  g_print ("Running...\n");
  g_main_loop_run (loop);

  /* Out of the main loop, clean up nicely */
  g_print ("Returned, stopping listening\n");
  gst_element_set_state (pipeline, GST_STATE_NULL);

  g_print ("Deleting pipeline\n");
  gst_object_unref (GST_OBJECT (pipeline));

  return 0;
}

