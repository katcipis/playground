#include <stdio.h>
#include <glib.h>
#include <gst/gst.h>
#include <gst/app/gstappsink.h>

static const int SLEEP_TIME_US = 500000;
static gboolean run_thread = TRUE;

static gboolean bus_call (GstBus *bus, GstMessage *msg, gpointer data)
{
   GMainLoop *loop = (GMainLoop *) data;

   switch (GST_MESSAGE_TYPE (msg))
   {

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

/* Thread that keeps pulling buffers from appsink */
static gpointer pull_func(gpointer data)
{
   GstAppSink* appsink = (GstAppSink*) data;
   GstBuffer* buffer = NULL;
      while(run_thread){
       g_usleep(SLEEP_TIME_US);
       if(appsink){
           g_debug("Calling pull buffer");
           buffer = gst_app_sink_pull_buffer(appsink);
           g_debug("Retuned from calling pull buffer");
   
           if(buffer){
               g_debug("appsink: buffer timestamp(%lli) size(%d)",
               GST_BUFFER_TIMESTAMP(buffer),
               GST_BUFFER_SIZE(buffer));
               gst_buffer_unref(buffer);
           }else{
               g_warning("NULL BUFFER PULLED !!");
           }

       }else{
           g_warning("NULL APPSINK !!!");
       }
   }

   return NULL;
}
 
static gboolean resume_time(gpointer data)
{
   g_debug("RESUME STARTED");
   gst_element_set_state(GST_ELEMENT(data), GST_STATE_PLAYING);
   g_debug("RESUME END");
   return FALSE;
}

static gboolean pause_time(gpointer data)
{
   g_debug("PAUSE STARTED");
   gst_element_set_state (GST_ELEMENT(data), GST_STATE_PAUSED);
   g_debug("PAUSE END");
   return FALSE;
}

int main(int argc, char *argv[])
{
   GstElement *pipeline = NULL;
   GstElement *source = NULL;
   GstElement *appsink = NULL;
   GstBus *bus = NULL;
   GMainLoop *loop = NULL;
   GThread * pull_thread = NULL;

   gst_init (&argc, &argv);
   loop = g_main_loop_new (NULL, FALSE);
      pipeline      = gst_pipeline_new ("pause-block-pipe");
   source        = gst_element_factory_make ("audiotestsrc", "source-test");
   appsink       = gst_element_factory_make ("appsink", "sink-test");

   if (!pipeline || !source || !appsink) {
       g_printerr ("Erro na criacao de um dos elementos do pipe.\n");
       return -1;
   }
   bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
   gst_bus_add_watch (bus, bus_call, loop);
   gst_object_unref (bus);

   gst_bin_add_many (GST_BIN(pipeline), source, appsink, NULL);
   if(!gst_element_link(source, appsink)){
       g_debug("Error linking source to appsink");
       return -1;
   }

   gst_app_sink_set_max_buffers((GstAppSink*)appsink, 10);

   pull_thread =  g_thread_create(pull_func, appsink, TRUE, NULL);
   if(!pull_thread){
       g_debug("Error creating thread!!");
       return -1;
   }
   gst_element_set_state (pipeline, GST_STATE_PLAYING);
   g_timeout_add_seconds(3, pause_time, pipeline);
   g_timeout_add_seconds(6, resume_time, pipeline);

   /* Iterate */
   g_print ("Running...\n");
   g_main_loop_run (loop);

   /* Out of the main loop, clean up nicely */
   g_print ("Terminating...\n");
   run_thread = FALSE;
   gst_element_set_state (pipeline, GST_STATE_NULL);

   g_print ("Deleting pipeline...\n");
   gst_object_unref (GST_OBJECT (pipeline));
   return 1;    
} 
