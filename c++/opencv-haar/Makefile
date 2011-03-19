all: opencv-test yuv-to-gray

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10 gstreamer-app-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10 gstreamer-app-0.10`

OPENCV_CFLAGS=`pkg-config --cflags opencv`
OPENCV_LFLAGS=`pkg-config --libs opencv` 

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS) $(OPENCV_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS) $(OPENCV_LFLAGS)
CPP=g++

opencv-test: opencv-test.cpp
	$(CPP) $(CFLAGS) $(LDFLAGS) $? -o $@

yuv-to-gray: yuv-to-gray.cpp
	$(CPP) $(CFLAGS) $(LDFLAGS) $? -o $@

clean:
	rm -rf opencv-test yuv-to-gray *.o
	rm -rf *.*~
