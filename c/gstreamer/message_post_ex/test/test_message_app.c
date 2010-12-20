#include <gst/gst.h>

static gboolean bus_call (GstBus *bus, GstMessage *msg, gpointer data)
{
   GMainLoop *loop = (GMainLoop *) data;

   switch (GST_MESSAGE_TYPE (msg))
   {

       case GST_MESSAGE_APPLICATION:
       {
       const GstStructure * msg_struct = gst_message_get_structure(msg);
       guint64 duration = 0;
       guint64 timestamp = 0;
       int stream_thread_id = 0;

       g_debug("APPLICATION CUSTOM MESSAGE !!!");
       g_debug("MESSAGE THREAD ID[%p]", g_thread_self());

       gst_structure_get_clock_time (msg_struct, "duration" , &duration);
       gst_structure_get_clock_time (msg_struct, "timestamp" , &timestamp);
       gst_structure_get_int (msg_struct, "stream_thread_id" , &stream_thread_id);
       
       g_debug("STREAM THREAD ID[0x%x]", stream_thread_id);
       g_debug("DURATION[%llu], TIMESTAMP[%llu]", duration, timestamp);
       g_debug("Testing string message, [%s]\n", gst_structure_get_string(msg_struct, "msg"));
       
       break;
       }

       case GST_MESSAGE_EOS:
       {
       g_print ("End of stream\n");
       g_main_loop_quit (loop);
       break;
       }

       case GST_MESSAGE_ERROR:
       {
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
       g_print("Msg type [%d], Msg name [%s]\n", GST_MESSAGE_TYPE (msg), GST_MESSAGE_TYPE_NAME(msg));
       break;
   }       return TRUE;
}

int main(int argc, char *argv[])
{
   GstElement *pipeline = NULL;
   GstElement *source,*test,*sink = NULL;
   GstBus *bus = NULL;
   GMainLoop *loop = NULL;

   gst_init (&argc, &argv);
   loop = g_main_loop_new (NULL, FALSE);
   pipeline  = gst_pipeline_new ("pause-block-pipe");
   source    = gst_element_factory_make ("audiotestsrc", "source-test");
   test      = gst_element_factory_make ("testmessage", "test");
   sink      = gst_element_factory_make ("fakesink", "sink-test");

   if (!pipeline || !source || !test || !sink) {
       g_printerr ("Erro na criacao de um dos elementos do pipe.\n");
       return -1;
   }

   bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
   gst_bus_add_watch (bus, bus_call, loop);
   gst_object_unref (bus);

   gst_bin_add_many (GST_BIN(pipeline), source, test, sink, NULL);
   
   if(!gst_element_link(source, test)){
       g_debug("Error linking source to test");
       return -1;
   }

   if(!gst_element_link(test, sink)){
       g_debug("Error linking test to sink");
       return -1;
   } 

   gst_element_set_state (pipeline, GST_STATE_PLAYING);
   
   /* Iterate */
   g_print ("Running...\n");
   g_main_loop_run (loop);

   /* Out of the main loop, clean up nicely */
   g_print ("Terminating...\n");
   gst_element_set_state (pipeline, GST_STATE_NULL);

   g_print ("Deleting pipeline...\n");
   gst_object_unref (GST_OBJECT (pipeline));
   return 1;
}

