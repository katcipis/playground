echo ""
echo "GStreamer 1.0 video transcoder. It will transcode videos to a more usual TV friendly format and also overlay subtitles."
echo "usage: $0 <video filepath> <subtitle (srt) filepath>"
echo ""

echo "Video filepath: "$1" Srt filepath: "$2

gst-launch-1.0 filesrc location=$1 ! decodebin name=decoder ! queue ! videoconvert ! subtitleoverlay font-desc="DejaVu Sans 40px" name=subtitle ! x264enc ! mp4mux name=muxer ! filesink location=$1-converted.mp4 decoder. ! audioconvert ! audioresample ! queue ! voaacenc ! muxer. filesrc location=$2 ! queue ! subparse ! subtitle.subtitle_sink
