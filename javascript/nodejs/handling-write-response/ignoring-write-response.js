"use strict";

var http = require('http');

var server = http.createServer(function(req, res) {
    res.setHeader('Content-Type', 'application/octet-stream');
    setInterval(function() {
        console.log("SERVER: writing data on the response");
        console.log("SERVER: write response: " + res.write(new Buffer(60000)));
    }, 50);
});

server.listen(8081);

var clientReq = http.get("http://localhost:8081", function(res) {
    console.log("CLIENT: Got response: " + res.statusCode);
    res.on('data', function() {
        console.log("CLIENT: got data");
    });
    res.on('end', function() {
        console.log("CLIENT: response ended");
    });
});
