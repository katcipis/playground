#include "libbar.h"

int main(int argc, char ** argv)
{
    gint a = libbar_a();
    gboolean b = libbar_b();
    gdouble c = 5.0;
    libbar_c(c);
    g_print("bar test: a[%i] b[%i]\n", a, b);
    return 0;
}

