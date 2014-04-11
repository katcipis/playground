var express    = require('express'),
app        = express(),
childProcess = require('child_process'),
http       = require('http');

app.get('/',  function(req, res) {
    var headers = {
        'Content-Type': 'application/octet-stream'
    }
    var args = [
        '--protocol', 'ssh', 
        '--address', '',
        '--file-location', '',
        '--login' , '',
        '--password', ''
    ];
    var streamerProcess = childProcess.spawn('./streamer', args);

    var parseMediaInformation = function(data) {
        streamerProcess.stdout.removeListener('data', parseMediaInformation);
        var info = JSON.parse(data);
        var mediaLength = info.len;
        var sendMedia = function(data) {
            if (data.length > mediaLength) {
                data = data.slice(0, mediaLength);
            }
            mediaLength -= data.length;
            res.write(data);
            if (mediaLength === 0) {
                res.end();
            }
        };
        streamerProcess.stdout.on('data', sendMedia);
        streamerProcess.stdin.write('\n');
    };

    streamerProcess.stdout.on('data', parseMediaInformation);
    res.writeHeader(200, headers);
});

var httpServer = http.createServer(app);
httpServer.listen(7777);
