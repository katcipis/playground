swig -lua gst.i
gcc -Wall -shared -I/usr/include/lua5.1 `pkg-config --cflags --libs gstreamer-0.10` gst_wrap.c -o gst.so
lua basic_test.lua
