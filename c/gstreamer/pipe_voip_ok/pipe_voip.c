#include <gst/gst.h>

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


int 
main (int argc, char *argv[]) 
{
  GstElement *send_pipe = NULL;
  GstElement *receive_pipe = NULL;
  GError* error = NULL;
  GMainLoop *loop;
  GstBus *bus; 

  gst_init (&argc,&argv);
  loop = g_main_loop_new (NULL, FALSE);
  
  send_pipe = gst_parse_launch("audiotestsrc ! audioconvert ! audio/x-raw-int,rate=44100,channels=1,endianness=1234,width=16,depth=16,signed=true ! udpsink host=127.0.0.1 port=5000", &error);

  if(error)
    g_warning("Warning [%s]", error->message);
  
  if(!send_pipe){
    g_warning("Error building send_pipe");
    exit (-1);
  }

  receive_pipe = gst_parse_launch("udpsrc port=5000 caps=audio/x-raw-int,rate=44100,channels=1,endianness=1234,width=16,depth=16,signed=true ! audioconvert ! pulsesink", &error);

  if(error)
    g_warning("Warning [%s]", error->message);

  if(!receive_pipe){
    g_warning("Error building receive_pipe");
    exit (-1);
  }
  
  bus = gst_pipeline_get_bus (GST_PIPELINE (send_pipe));
  gst_bus_add_watch (bus, bus_call, loop);
  gst_object_unref (bus);

  bus = gst_pipeline_get_bus (GST_PIPELINE (receive_pipe));
  gst_bus_add_watch (bus, bus_call, loop);
  gst_object_unref (bus);

  gst_element_set_state (send_pipe, GST_STATE_PLAYING);
  gst_element_set_state (receive_pipe, GST_STATE_PLAYING);  

  /* Iterate */
  g_print ("Running...\n");
  g_main_loop_run (loop);

  /* Out of the main loop, clean up nicely */
  gst_element_set_state (send_pipe, GST_STATE_NULL);
  gst_element_set_state (receive_pipe, GST_STATE_NULL);

  g_print ("Deleting pipeline\n");
  gst_object_unref (GST_OBJECT (receive_pipe));
  gst_object_unref (GST_OBJECT (send_pipe));

  exit (0);
}



