#!/bin/nash

var remoteip=$ARGS[1]

gst-launch-1.0 -v pulsesrc ! alawenc ! rtppcmapay ! udpsink host=$remoteip port=5001 async=false udpsrc port=5001 caps="application/x-rtp,media=audio,payload=8,clock-rate=8000,encoding-name=PCMA" ! rtppcmadepay ! pulsesink
