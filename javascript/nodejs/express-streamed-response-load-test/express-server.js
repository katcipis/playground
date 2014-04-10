var express    = require('express'),
app        = express(),
http       = require('http');

app.get('/',  function(req, res) {
    var headers = {
        'Content-Type': 'application/octet-stream'
    }
    res.writeHeader(200, headers);
    var sendStreamTimerId = setInterval(function () {
        res.write(new Buffer(1024));
    }, 200);
    setTimeout(function () {
        clearInterval(sendStreamTimerId);
        res.end();
    }, 60000);
});

var httpServer = http.createServer(app);
httpServer.listen(8606);
