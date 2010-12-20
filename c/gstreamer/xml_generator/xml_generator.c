#include <gst/gst.h>

int 
main (int argc, char *argv[]) 
{
  GstElement *pipeline = NULL;
  GError* error = NULL;
  FILE* output_file = NULL;

  gst_init (&argc,&argv);

  if (argc != 3) {
    g_print ("usage: %s <gst-launch-like pipeline> <xml file_path>\n", argv[0]);
    exit (-1);
  }

  output_file = fopen (argv[2], "w");
  if(!output_file){
    g_warning("Error opening file[%s]", argv[2]);
    exit (-1);
  }

  pipeline = gst_parse_launch(argv[1], &error);

  if(error)
    g_warning("Warning [%s]", error->message);
  
  if(!pipeline){
    g_warning("Error building pipeline [%s]", argv[1]);
    fclose(output_file);
    exit (-1);
  }
 
  /* write the bin to a file */
  gst_xml_write_file (GST_ELEMENT (pipeline), output_file);
  
  fclose(output_file);
  gst_object_unref (GST_OBJECT (pipeline));
  exit (0);
}

