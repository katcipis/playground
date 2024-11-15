%module gstpipeline
%{
#include <gst/gstpipeline.h>
#include <gst/gstbin.h>
%}

typedef enum {
  GST_PIPELINE_FLAG_FIXED_CLOCK        = (GST_BIN_FLAG_LAST << 0),
  GST_PIPELINE_FLAG_LAST               = (GST_BIN_FLAG_LAST << 4)
} GstPipelineFlags;

GstElement*     gst_pipeline_new                (const char *name);
GstBus*         gst_pipeline_get_bus            (GstPipeline *pipeline);

void            gst_pipeline_use_clock          (GstPipeline *pipeline, GstClock *clock);
gboolean        gst_pipeline_set_clock          (GstPipeline *pipeline, GstClock *clock);
GstClock*       gst_pipeline_get_clock          (GstPipeline *pipeline);
void            gst_pipeline_auto_clock         (GstPipeline *pipeline);

void            gst_pipeline_set_delay          (GstPipeline *pipeline, GstClockTime delay);
GstClockTime    gst_pipeline_get_delay          (GstPipeline *pipeline);

void            gst_pipeline_set_auto_flush_bus (GstPipeline *pipeline, gboolean auto_flush);
gboolean        gst_pipeline_get_auto_flush_bus (GstPipeline *pipeline);

