tolua -n gst -o gst.c gst.pkg
gcc -Wall -shared -I/usr/include/lua5.1 `pkg-config --cflags --libs gstreamer-0.10` /usr/lib/libtolua.a gst.c -o gst.so
lua basic_test.lua
