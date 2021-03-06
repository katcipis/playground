%module gstutils
%{

#include <gst/gstutils.h>
#include <glib.h>
#include <gst/gstbin.h>
#include <gst/gstparse.h>

%}

void                    gst_element_create_all_pads     (GstElement *element);

gboolean                gst_element_link                (GstElement *src, GstElement *dest);
void                    gst_element_unlink              (GstElement *src, GstElement *dest);


gboolean                gst_element_link_pads           (GstElement *src, const gchar *srcpadname,
                                                         GstElement *dest, const gchar *destpadname);
void                    gst_element_unlink_pads         (GstElement *src, const gchar *srcpadname,
                                                         GstElement *dest, const gchar *destpadname);

gboolean                gst_element_seek_simple         (GstElement   *element,
                                                         GstFormat     format,
                                                         GstSeekFlags  seek_flags,
                                                         gint64        seek_pos);


gboolean                gst_element_query_position      (GstElement *element, GstFormat *format,
                                                         gint64 *cur);
gboolean                gst_element_query_duration      (GstElement *element, GstFormat *format,
                                                         gint64 *duration);
gboolean                gst_element_query_convert       (GstElement *element, GstFormat src_format, gint64 src_val,
                                                         GstFormat *dest_format, gint64 *dest_val);



