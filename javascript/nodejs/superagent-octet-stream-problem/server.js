"use strict";

var http = require('http');
var octetStream = require('./octet-stream.js').getOctetStream();

http.createServer(function(req, res) {
    res.setHeader('Content-Type', 'application/octet-stream');
    res.setHeader('Content-Length', octetStream.length);
    res.write(octetStream);
    res.end();
}).listen(8080);
