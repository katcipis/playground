%module gstelementfactory
%{

#include <gst/gstconfig.h>
#include <gst/gstelement.h>
#include <gst/gstobject.h>
#include <gst/gstplugin.h>
#include <gst/gstpluginfeature.h>
#include <gst/gstiterator.h>

%}

GstElement*             gst_element_factory_make                (const char *factoryname, const char *name);

