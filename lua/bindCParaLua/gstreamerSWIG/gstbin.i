%module gstbin
%{
#include <gst/gstbin.h>
#include <gst/gstelement.h>
#include <gst/gstiterator.h>
#include <gst/gstbus.h>

%}

GstElement*     gst_bin_new                     (const char *name);
gboolean        gst_bin_add                     (GstBin *bin, GstElement *element);
gboolean        gst_bin_remove                  (GstBin *bin, GstElement *element);

GstElement*     gst_bin_get_by_name              (GstBin *bin, const char *name);
GstElement*     gst_bin_get_by_name_recurse_up   (GstBin *bin, const char *name);
GstElement*     gst_bin_get_by_interface         (GstBin *bin, GType iface);

gboolean        gst_bin_recalculate_latency      (GstBin * bin);


%native(lua_gst_bin) int lua_gst_bin(lua_State* L);  

%{
int lua_gst_bin(lua_State*L) // my native code
{
     int SWIG_arg = 0;
     GstElement *arg1 = (GstElement *) 0 ;
     gboolean result;

     SWIG_check_num_args("lua_gst_bin",1,1)
     if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("lua_gst_bin",1,"void *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_GstElement,0))){
    SWIG_fail_ptr("lua_gst_bin",1,SWIGTYPE_p_GstElement);
  }
  result = 1;
  {
    GstBin * resultptr;
    resultptr = GST_BIN(arg1);
    SWIG_NewPointerObj(L,(void *) resultptr,SWIGTYPE_p_GstBin,1); SWIG_arg++;
  }
  return SWIG_arg;

  if(0) SWIG_fail;

fail:
  lua_error(L);
  return SWIG_arg;
}
%}

