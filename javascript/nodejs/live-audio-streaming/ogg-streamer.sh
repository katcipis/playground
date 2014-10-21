#!/bin/sh

gst-launch-1.0 -q audiotestsrc is-live=true ! audioconvert ! audioresample ! audio/x-raw,rate=8000,channels=1,format=S16LE ! audioconvert ! vorbisenc ! oggmux ! fdsink
