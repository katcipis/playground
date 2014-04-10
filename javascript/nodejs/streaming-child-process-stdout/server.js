var express    = require('express'),
app        = express(),
childProcess = require('child_process'),
http       = require('http');

app.get('/',  function(req, res) {
    var headers = {
        'Content-Type': 'application/octet-stream'
    }
    res.writeHeader(200, headers);
    streamerProcess = childProcess.spawn('./streamer');
    streamerProcess.stdout.on('data', function(data) {
        res.write(data);
    });
    streamerProcess.stdout.on('end', function(data) {
        res.end();
    });
});

var httpServer = http.createServer(app);
httpServer.listen(7777);
