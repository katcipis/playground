/*
  Developed by Tiago Katcipis <tiagokatcipis@gmail.com>
  Equivalent test pipe: gst-launch -v gnomevfssrc location="ssh://user@host:file" ! fakesink
*/

#include <gst/gst.h>
#include <glib.h>

static int pipe_count = 0;

static gboolean
bus_call (GstBus     *bus,
          GstMessage *msg,
          gpointer    data)
{
  GMainLoop *loop = (GMainLoop *) data;

  switch (GST_MESSAGE_TYPE (msg)) {

    case GST_MESSAGE_EOS:
      g_print ("End of stream\n");
      --pipe_count; 
      if(pipe_count == 0)
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

int
main (int   argc,
      char *argv[])
{
  GMainLoop *loop;
  GstElement **pipelines;
  int i;

  /* Initialisation */
  gst_init (&argc, &argv);
  loop = g_main_loop_new (NULL, FALSE);

  if(argc < 3) {
      g_printerr ("Usage: %s [url] [number of pipes] \n", argv[0]);
      return -1;
  }

  pipe_count = atoi(argv[2]);
  pipelines = g_new0(GstElement*, atoi(argv[2])); 
  g_print("Location is [%s] \n", argv[1]); 

  for(i = 0; i < atoi(argv[2]); i++) {
      GstElement *pipeline, *source, *sink;
      GstBus *bus;

      /* Create gstreamer elements */
      pipeline = gst_pipeline_new ("gnomevfs-src-test");
      source   = gst_element_factory_make ("gnomevfssrc", NULL);
      sink     = gst_element_factory_make ("fakesink", NULL);

      if (!pipeline || !source || !sink) {
          g_printerr ("One element could not be created. Exiting.\n");
          return -1;
      }
      /* Set up the pipeline */
      /* we set the input filename to the src element */
      g_object_set (G_OBJECT (source), "location", argv[1] , NULL);

      /* we add a message handler */
      bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
      gst_bus_add_watch (bus, bus_call, loop);
      gst_object_unref (bus);

      /* we add all elements into the pipeline */
      gst_bin_add_many (GST_BIN (pipeline), source, sink, NULL);
 
      /* we link the elements together */
      if(!gst_element_link (source, sink)){
          g_warning("Error linking source to sink");
          gst_object_unref (GST_OBJECT (pipeline));
          return 0;
      }
   
      /* Set the pipeline to "playing" state*/
      gst_element_set_state (pipeline, GST_STATE_PLAYING);

      /* Iterate */
      g_print ("Running[%d]...\n", i);
      pipelines[i] = pipeline;
  }

  g_main_loop_run (loop);

  for(i = 0; i < atoi(argv[2]); i++) {
      /* Out of the main loop, clean up nicely */
      gst_element_set_state (pipelines[i], GST_STATE_NULL);

      g_print ("Deleting pipeline [%d]\n", i);
      gst_object_unref (GST_OBJECT (pipelines[i]));
  }

  g_print("Exiting \n");
  return 0;
}


