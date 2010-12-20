#include <stdio.h>
#include <stdlib.h>

#include <libgnomevfs/gnome-vfs.h>
#include <libgnomevfs/gnome-vfs-utils.h>

#define BYTES_TO_PROCESS 256

static char *input_uri_string = NULL;
static char *output_uri_string = NULL;
static int streams = 0;
static GMainLoop *loop = NULL;

static int print_error (GnomeVFSResult result, const char *uri_string)
{
  const char *error_string;
  /* get the string corresponding to this GnomeVFSResult value */
  error_string = gnome_vfs_result_to_string (result);
  printf ("Error %s occured opening location %s\n", error_string, uri_string);
  return 1;
}

static int play (const char *input_uri_string, const char *output_uri_string)
{
  GnomeVFSHandle *read_handle, *write_handle;
  GnomeVFSFileSize bytes_read, bytes_written;
  guint buffer[BYTES_TO_PROCESS];
  GnomeVFSResult result;
  
  GnomeVFSFileInfo *info;
  GnomeVFSFileInfoOptions options;
  guint64 size;
  GnomeVFSURI *uri;

  /* open the input file for read access */
  result = gnome_vfs_open (&read_handle, input_uri_string, GNOME_VFS_OPEN_READ);
  /* if the operation was not successful, print the error and abort */
  if (result != GNOME_VFS_OK) return print_error (result, input_uri_string);
  
  size = -1;
  uri = gnome_vfs_uri_new (input_uri_string);
  info = gnome_vfs_file_info_new ();
  options = GNOME_VFS_FILE_INFO_DEFAULT | GNOME_VFS_FILE_INFO_FOLLOW_LINKS;
  result = gnome_vfs_get_file_info_from_handle (read_handle, info, options);
  if (result == GNOME_VFS_OK) {
    if ((info->valid_fields & GNOME_VFS_FILE_INFO_FIELDS_SIZE) != 0) {
      size = info->size;
      //GST_DEBUG_OBJECT (src, "from handle: %" G_GUINT64_FORMAT " bytes", size);
	  printf ("from handle...\n");
    } else if (gnome_vfs_uri_is_local (uri)) {
      //GST_DEBUG_OBJECT (src, "file size not known, file local, trying fallback");
	  printf ("file size not know, file local, trying fallback\n");
      result = gnome_vfs_get_file_info_uri (uri, info, options);
      if (result == GNOME_VFS_OK && (info->valid_fields & GNOME_VFS_FILE_INFO_FIELDS_SIZE) != 0) {
        size = info->size;
        //GST_DEBUG_OBJECT (src, "from uri: %" G_GUINT64_FORMAT " bytes", size);
		printf ("from uri...\n");
      }
    }
  } else {
    //GST_WARNING_OBJECT (src, "getting info failed: %s", gnome_vfs_result_to_string (res));
	printf ("getting info failed: %s\n", gnome_vfs_result_to_string (result));
  }
  gnome_vfs_file_info_unref (info);

  printf ("========================================== COPYING ====================================\n");
  /* we use create instead of open, because open will not create the file if it does
     not already exist. The last argument is the permissions to use if the file is created,
     the second to last tells GnomeVFS that its ok if the file already exists, and just open it */
  result = gnome_vfs_create (&write_handle, output_uri_string, GNOME_VFS_OPEN_WRITE, FALSE, 0777);
  if (result != GNOME_VFS_OK) return print_error (result, output_uri_string);

  /* seek to the end of the output uri so we will append rather than overwrite */
  /* therefore, we seek 0 bytes relative to the end of the file */
  result = gnome_vfs_seek (write_handle, GNOME_VFS_SEEK_END, 0);

  do {
    /* read data from the input uri */
    result = gnome_vfs_read (read_handle, buffer, BYTES_TO_PROCESS, &bytes_read);
    if (result != GNOME_VFS_OK) return print_error (result, input_uri_string);

    /* now write the data we read out to the output uri */
    result = gnome_vfs_write (write_handle, buffer, bytes_read, &bytes_written);
    if (result != GNOME_VFS_OK) return print_error (result, output_uri_string);
  } while(bytes_read == BYTES_TO_PROCESS); 

  return 0;
}

static gpointer stream_run(gpointer data)
{
  int i = (int)data;
  char* output = g_strdup_printf("%s-%d", output_uri_string, i);
  play(input_uri_string, output);
  g_free(output);
  if (g_atomic_int_dec_and_test(&streams))
    g_main_loop_quit(loop);
  return NULL;
}

int main (int argc, char **argv)
{
  int i;

  if(argc < 3){
    printf("Usage: %s [ssh uri] [local path to write the files] [number of copying threads]\n", argv[0]);
    return -1;
  }

  streams = atoi(argv[3]);

  g_thread_init (NULL);

  /* remember to initialize GnomeVFS! */
  if (!gnome_vfs_init ()) {
    printf ("Could not initialize GnomeVFS\n");
    return 1;
  }

  /* Convert the user supplied filenames into proper GnomeVFS URIs */
  input_uri_string = gnome_vfs_make_uri_from_shell_arg (argv[1]);
  output_uri_string = gnome_vfs_make_uri_from_shell_arg (argv[2]);

  for(i = 0; i < streams; i++)
    g_thread_create(stream_run, (gpointer)i, TRUE, NULL);

  loop = g_main_loop_new(NULL, TRUE);
  g_main_loop_run(loop);

  g_free (input_uri_string);
  g_free (output_uri_string);

  return 0;
}

