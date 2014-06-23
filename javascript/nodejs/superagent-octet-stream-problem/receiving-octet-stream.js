"use strict";

var request = require('superagent');
var octetStream = require('./octet-stream.js').getOctetStream();

request
.get('http://localhost:8080/')
.end(function(err, res) {
    if (err) throw err;

    console.log("Received response:");
    console.log(res);
    
    var receivedBuffer = new Buffer(res.text);

    console.log("\nExpected buffer len: " + expectedBuffer.length + " data : ");
    console.log(expectedBuffer);
    console.log("Received buffer len: " + receivedBuffer.length + " data : ");
    console.log(receivedBuffer);

    if (expectedBuffer.length !== receivedBuffer.length) {
         throw new Error("buffers size does not match");
    }
});
