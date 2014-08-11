echo ""
echo "GStreamer 1.0 video transcoder."
echo "usage: $0 <filename>"
echo ""

gst-launch-1.0 filesrc location=$1 ! decodebin name=decoder ! queue ! videoconvert ! x264enc ! mp4mux name=muxer ! filesink location=$1-converted.mp4 decoder. ! queue ! voaacenc ! muxer.
