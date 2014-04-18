var childProcess = require('child_process'),
http = require('http');

var httpServer = http.createServer (function(req, res) {
    var headers = {
        'Content-Type': 'application/octet-stream'
    }
    var streamerProcess = childProcess.spawn('./streamer');
    streamerProcess.stdout.on('data', function(data) {
        res.write(data);
    });

    streamerProcess.on('exit', function() {
        res.end();
        streamerProcess.removeAllListeners();
        streamerProcess.stderr.removeAllListeners();
        streamerProcess.stdout.removeAllListeners();
    });

    res.writeHeader(200, headers);
});

httpServer.listen(7777);
