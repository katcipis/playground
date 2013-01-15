#include <glib.h>

/* lets mock libfoo_a */
gint libfoo_a (void)
{
    g_print("libfoo_a: mocked\n");
    return 144000;
}
