var express    = require('express'),
app        = express(),
http       = require('http');

app.get('/',  function(req, res) {
    var headers = {
        'Content-Type': 'audio/ogg'
    }
    res.writeHeader(200, headers);
    var sendStreamedResponse = setInterval(function () {
        res.write(new Buffer(1024));
    }, 200);
    setInterval(function () {
        clearInterval(sendStreamedResponse);
        res.end();
    }, 60000);
});

var httpServer = http.createServer(app);
httpServer.listen(8606);
