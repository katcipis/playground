#include "libfoo.h"

int main(int argc, char ** argv)
{
    gint a = libfoo_a();
    gboolean b = libfoo_b();
    gdouble c = 5.0;
    libfoo_c(c);
    g_print("foo test: a[%i] b[%i]\n", a, b);
    return 0;
}

