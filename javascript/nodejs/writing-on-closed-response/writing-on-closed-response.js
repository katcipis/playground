"use strict";

var express = require('express');
var http = require('http');

var app = express();

app.get('/',  function(req, res) {
    res.setHeader('Content-Type', 'application/octet-stream');
    res.on("close", function() {
        console.log("SERVER: RESPONSE CLOSED BY THE CLIENT !!!!");
    });
    setInterval(function() {
        console.log("SERVER: writing data on the response");
        res.write(new Buffer(64));
    }, 1000);
});

var server = http.createServer(app);
server.listen(8080);

var clientReq = http.get("http://localhost:8080", function(res) {
    console.log("CLIENT: Got response: " + res.statusCode);
    console.log("CLIENT: Aborting the request to close the connection");
    clientReq.abort();
});
