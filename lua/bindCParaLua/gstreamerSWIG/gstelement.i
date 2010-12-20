%module gstelement
%{
#include <gst/gstelement.h>
#include <gst/gstconfig.h>
#include <gst/gstobject.h>
#include <gst/gstpad.h>
#include <gst/gstbus.h>
#include <gst/gstclock.h>
#include <gst/gstelementfactory.h>
#include <gst/gstplugin.h>
#include <gst/gstpluginfeature.h>
#include <gst/gstindex.h>
#include <gst/gstindexfactory.h>
#include <gst/gstiterator.h>
#include <gst/gstmessage.h>
#include <gst/gsttaglist.h>
%}

typedef enum {
  GST_STATE_VOID_PENDING        = 0,
  GST_STATE_NULL                = 1,
  GST_STATE_READY               = 2,
  GST_STATE_PAUSED              = 3,
  GST_STATE_PLAYING             = 4
} GstState;

typedef enum {
  GST_STATE_CHANGE_FAILURE             = 0,
  GST_STATE_CHANGE_SUCCESS             = 1,
  GST_STATE_CHANGE_ASYNC               = 2,
  GST_STATE_CHANGE_NO_PREROLL          = 3
} GstStateChangeReturn;

typedef enum 
{
  GST_STATE_CHANGE_NULL_TO_READY        = (GST_STATE_NULL<<3) | GST_STATE_READY,
  GST_STATE_CHANGE_READY_TO_PAUSED      = (GST_STATE_READY<<3) | GST_STATE_PAUSED,
  GST_STATE_CHANGE_PAUSED_TO_PLAYING    = (GST_STATE_PAUSED<<3) | GST_STATE_PLAYING,
  GST_STATE_CHANGE_PLAYING_TO_PAUSED    = (GST_STATE_PLAYING<<3) | GST_STATE_PAUSED,
  GST_STATE_CHANGE_PAUSED_TO_READY      = (GST_STATE_PAUSED<<3) | GST_STATE_READY,
  GST_STATE_CHANGE_READY_TO_NULL        = (GST_STATE_READY<<3) | GST_STATE_NULL
} GstStateChange;

typedef enum
{
  GST_ELEMENT_LOCKED_STATE      = (GST_OBJECT_FLAG_LAST << 0),
  GST_ELEMENT_IS_SINK           = (GST_OBJECT_FLAG_LAST << 1),
  GST_ELEMENT_UNPARENTING       = (GST_OBJECT_FLAG_LAST << 2),
  /* padding */
  GST_ELEMENT_FLAG_LAST         = (GST_OBJECT_FLAG_LAST << 16)
} GstElementFlags;

#define                 gst_element_get_name(elem)      gst_object_get_name(GST_OBJECT_CAST(elem))
#define                 gst_element_set_name(elem,name) gst_object_set_name(GST_OBJECT_CAST(elem),name)
#define                 gst_element_get_parent(elem)    gst_object_get_parent(GST_OBJECT_CAST(elem))

gboolean                gst_element_requires_clock      (GstElement *element);
gboolean                gst_element_provides_clock      (GstElement *element);
GstClock*               gst_element_provide_clock       (GstElement *element);
GstClock*               gst_element_get_clock           (GstElement *element);
gboolean                gst_element_set_clock           (GstElement *element, GstClock *clock);
void                    gst_element_set_base_time       (GstElement *element, GstClockTime time);
GstClockTime            gst_element_get_base_time       (GstElement *element);
void                    gst_element_set_start_time      (GstElement *element, GstClockTime time);
GstClockTime            gst_element_get_start_time      (GstElement *element);

gboolean                gst_element_is_indexable        (GstElement *element);
void                    gst_element_set_index           (GstElement *element, GstIndex *index);
GstIndex*               gst_element_get_index           (GstElement *element);

void                    gst_element_set_bus             (GstElement * element, GstBus * bus);
GstBus *                gst_element_get_bus             (GstElement * element);

GstPad*                 gst_element_get_static_pad      (GstElement *element, const gchar *name);
GstPad*                 gst_element_get_request_pad     (GstElement *element, const gchar *name);
void                    gst_element_release_request_pad (GstElement *element, GstPad *pad);

gboolean                gst_element_send_event          (GstElement *element, GstEvent *event);
gboolean                gst_element_seek                (GstElement *element, gdouble rate,
                                                         GstFormat format, GstSeekFlags flags,
                                                         GstSeekType cur_type, gint64 cur,
                                                         GstSeekType stop_type, gint64 stop);

GstQueryType*           gst_element_get_query_types     (GstElement *element);
gboolean                gst_element_query               (GstElement *element, GstQuery *query);

gboolean                gst_element_is_locked_state     (GstElement *element);
gboolean                gst_element_set_locked_state    (GstElement *element, gboolean locked_state);
gboolean                gst_element_sync_state_with_parent (GstElement *element);

GstStateChangeReturn    gst_element_get_state           (GstElement * element,
                                                         GstState * state,
                                                         GstState * pending,
                                                         GstClockTime timeout);
GstStateChangeReturn    gst_element_set_state           (GstElement *element, GstState state);

void                    gst_element_abort_state         (GstElement * element);
GstStateChangeReturn    gst_element_change_state        (GstElement * element,
                                                         GstStateChange transition);
GstStateChangeReturn    gst_element_continue_state      (GstElement * element,
                                                         GstStateChangeReturn ret);
void                    gst_element_lost_state          (GstElement * element);
void                    gst_element_lost_state_full     (GstElement * element, gboolean new_base_time);

GstElementFactory*      gst_element_get_factory         (GstElement *element);


