/*
  Developed by Tiago Katcipis <tiago.katcipis@digitro.com.br>
  Equivalent test pipe: gst-launch -v --gst-plugin-path=../../ giosrc location="file:///path-to-file"! decodebin ! alawenc ! fakesink
*/

#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <glib.h>
#define TIMEOUT_SEEK 5

static int counter = 0;
static gboolean volta_inicio = FALSE;

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
  GstElement *converter = (GstElement *) data;

  /* We can now link this pad with the converter sink pad */
  g_debug ("Dynamic pad created, linking wavparser/converter\n");

  sinkpad = gst_element_get_static_pad (converter, "sink");
  if(gst_pad_link (pad, sinkpad) != GST_PAD_LINK_OK){
      g_warning("Error linking wavparser pad to audioconvert pad");
  }
  gst_object_unref (sinkpad);
}


static gboolean set_new_position(gpointer pipeline)
{
    gint64 seek_pos = 0;
    GRand* rand_generator = g_rand_new();

    g_debug("Starting seek :-)");
    if(counter >= 10){
        g_rand_free (rand_generator);
        return FALSE;
    }
    counter++;
    if(volta_inicio){
        seek_pos = 0;
        volta_inicio = FALSE;
    }else{
        seek_pos = GST_SECOND * g_rand_int_range(rand_generator, 1, 30);
        volta_inicio = TRUE;
    }
     
    if(!gst_element_seek_simple(pipeline, GST_FORMAT_TIME, 
                                    GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_KEY_UNIT, 
                                    seek_pos)){
        g_debug("Error seeking!");
        g_rand_free (rand_generator);
        return TRUE;
    }
    
    g_debug("Seeked with success :-), position set is[%lld]", seek_pos / GST_SECOND);
    g_rand_free (rand_generator);
    return TRUE;
}

static void new_buffer_added (GstAppSink *appsink, gpointer user_data)
{
    GstBuffer* buffer = gst_app_sink_pull_buffer (appsink);
    g_debug("Buffer recebido tamanho[%d] duracao[%lli] timestamp[%lli]", 
            GST_BUFFER_SIZE(buffer), GST_BUFFER_DURATION(buffer) / GST_SECOND, GST_BUFFER_TIMESTAMP(buffer) / GST_SECOND);
    gst_buffer_unref(buffer);
}
 
int
main (int   argc,
      char *argv[])
{
  GMainLoop *loop;

  GstElement *pipeline, *source, *wavparse, *convert, *encoder, *sink;
  GstBus *bus;

  /* Initialisation */
  gst_init (&argc, &argv);
  loop = g_main_loop_new (NULL, FALSE);

  /* Create gstreamer elements */
  pipeline = gst_pipeline_new ("remove-silence-test");
  source   = gst_element_factory_make ("giosrc", "gio-src");
  wavparse = gst_element_factory_make ("wavparse", "wav_parser");
  convert  = gst_element_factory_make ("audioconvert",  "audio_convert");
  encoder = gst_element_factory_make ("speexenc", "encoder");
  sink     = gst_element_factory_make ("appsink", "app-sink");

  if(argc < 2) {
      g_printerr ("Usage: %s [wav pcm linear url]\n", argv[0]);
      return -1;
  }

  if (!pipeline || !source || !sink || !wavparse || !convert || !sink) {
    g_printerr ("One element could not be created. Exiting.\n");
    return -1;
  }


  /* Set up the pipeline */
  /* we set the input filename to the sink element */
  g_object_set (G_OBJECT (source), "location", argv[1] , NULL);
  g_object_set (G_OBJECT (encoder),"remove", TRUE, NULL);
  g_object_set (G_OBJECT (sink), "emit-signals", TRUE, NULL);
  
  /* we add a message handler */
  bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
  gst_bus_add_watch (bus, bus_call, loop);
  gst_object_unref (bus);

  /* we add all elements into the pipeline */
  gst_bin_add_many (GST_BIN (pipeline),
                    source, wavparse, convert, encoder, sink, NULL);

  /* we link the elements together */
  if(!gst_element_link (source, wavparse)){
      g_warning("Error linking source to wavparse");
      gst_object_unref (GST_OBJECT (pipeline));
      return 0;
  }
  
  /*
    wavparse will be connected to audioconvert dinamicaly, because wavparse may not have a src pad when
    it is created, so when the src pad is created on runtime the on_pad_added function will handle
    the event getting the pad and connecting it to the audioconvert object.
  */
  g_signal_connect (wavparse, "pad-added", G_CALLBACK (on_pad_added), convert);
  g_signal_connect (sink, "new-buffer", G_CALLBACK (new_buffer_added), NULL);

  if(!gst_element_link (convert, encoder)){
    g_printerr("Error linking convert to encoder\n");
    gst_object_unref (GST_OBJECT (pipeline));
    return -1;
  }

  if(!gst_element_link (encoder, sink)){
    g_printerr("Error linking encoder to appsink\n");
    gst_object_unref (GST_OBJECT (pipeline));
    return -1;
  }

  /* Set the pipeline to "playing" state*/
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Iterate */
  g_print ("Running...\n");
  g_timeout_add_seconds(TIMEOUT_SEEK, set_new_position, pipeline);
  g_main_loop_run (loop);

  /* Out of the main loop, clean up nicely */
  gst_element_set_state (pipeline, GST_STATE_NULL);

  g_print ("Deleting pipeline\n");
  gst_object_unref (GST_OBJECT (pipeline));

  return 0;
}


