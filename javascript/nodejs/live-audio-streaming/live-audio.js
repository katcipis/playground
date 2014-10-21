var http = require("http");
var fs = require("fs");
var childProcess = require("child_process");

var server = http.createServer(function(req, res) {

    if (req.url === "/live-audio") {
        var liveStreamer = childProcess.spawn("./mp3-streamer.sh");
        res.setHeader("Content-Type", "audio/mp3");
        liveStreamer.stdout.pipe(res);
        liveStreamer.stderr.setEncoding('utf-8');
        liveStreamer.stderr.on('data', function(data) {
            console.warn(data);
        });
        return;
    }

    res.write(fs.readFileSync("./index.html"));
    res.end();
});

server.listen(8081);
