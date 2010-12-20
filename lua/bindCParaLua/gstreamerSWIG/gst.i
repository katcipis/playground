%module gst
%{
#include <gst/gst.h>
%}

%include "gstelement.i"
%include "gstelementfactory.i"
%include "gstpipeline.i"
%include "gstbin.i"
%include "gstutils.i"

void            gst_init                        (int *argc, char **argv[]);
gboolean        gst_init_check                  (int *argc, char **argv[], GError ** err);

GOptionGroup *  gst_init_get_option_group       (void);
void            gst_deinit                      (void);

void            gst_version                     (guint *major, guint *minor,
                                                 guint *micro, guint *nano);
gchar *         gst_version_string              (void);

gboolean        gst_segtrap_is_enabled          (void);
void            gst_segtrap_set_enabled         (gboolean enabled);

gboolean        gst_registry_fork_is_enabled    (void);
void            gst_registry_fork_set_enabled   (gboolean enabled);

gboolean        gst_update_registry (void);
