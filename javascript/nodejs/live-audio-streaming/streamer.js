
module.exports.streamAudio = function streamAudio(streamer, contentType) {
    var liveStreamer = childProcess.spawn(streamer);
    res.setHeader("Content-Type", contentType);
    liveStreamer.stdout.pipe(res);
    liveStreamer.stderr.setEncoding('utf-8');
    liveStreamer.stderr.on('data', function(data) {
        console.warn(data);
    });
}
