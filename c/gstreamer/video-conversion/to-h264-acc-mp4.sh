echo ""
echo "usage: $0 <filename>"
echo ""

gst-launch-0.10 filesrc location=$1 ! decodebin2 name=decoder ! queue ! ffmpegcolorspace ! x264enc ! mp4mux name=muxer ! filesink location=converted-video.mp4 decoder. ! queue ! voaacenc ! muxer.
