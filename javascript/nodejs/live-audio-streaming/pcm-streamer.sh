#!/bin/sh

gst-launch-1.0 audiotestsrc ! audioconvert ! audioresample ! audio/x-raw,rate=8000,channels=1,format=S16LE ! audioconvert ! wavenc ! fdsink
