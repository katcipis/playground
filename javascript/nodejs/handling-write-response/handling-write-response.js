"use strict";

var http = require('http');

var server = http.createServer(function(req, res) {
    res.setHeader('Content-Type', 'application/octet-stream');
    var canWriteData = true;
    res.on('drain', function() {
        console.log("SERVER: data drained, we can write now");
        canWriteData = true;
    });

    setInterval(function() {
        console.log("SERVER: writing data on the response");
        if (canWriteData) {
            console.log("SERVER: we can write data directly");
            canWriteData = res.write(new Buffer(60000));
            console.log("SERVER: canWriteData: " + canWriteData);
        } else {
            console.log("SERVER: cant write data right now, waiting for drain");
        }
    }, 50);
});

server.listen(8080);

var clientReq = http.get("http://localhost:8080", function(res) {
    console.log("CLIENT: Got response: " + res.statusCode);
    res.on('data', function() {
        console.log("CLIENT: got data");
    });
    res.on('end', function() {
        console.log("CLIENT: response ended");
    });
});
