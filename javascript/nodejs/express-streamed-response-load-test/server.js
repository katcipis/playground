var http = require('http');

var httpServer = http.createServer(function(req, res) {
    var headers = {
        'Content-Type': 'application/octet-stream'
    }
    res.writeHeader(200, headers);
    var sendStreamingTimerId = setInterval(function () {
        res.write(new Buffer(1024));
    }, 200);
    setTimeout(function () {
        clearInterval(sendStreamingTimerId);
        res.end();
    }, 60000);
});

httpServer.listen(8606);
