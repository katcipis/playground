"use strict";

var request = require('supertest');
var express = require('express');


var app = express();
var expectedBuffer = new Buffer(10);

expectedBuffer[0] = 234;
expectedBuffer[1] = 235;
expectedBuffer[2] = 196;
expectedBuffer[3] = 189;
expectedBuffer[4] = 10;
expectedBuffer[5] = 183;
expectedBuffer[6] = 66;
expectedBuffer[7] = 150;
expectedBuffer[8] = 173;
expectedBuffer[9] = 235;

app.get('/',  function(req, res) {
    res.setHeader('Content-Type', 'application/octet-stream');
    res.setHeader('Content-Length', expectedBuffer.length);
    res.write(expectedBuffer);
    res.end();
});

describe('Streaming data test', function() {

    it('should send all data correctly', function(done) {
        request(app)
        .get('/')
        .expect(200)
        .expect(function(res) {
            if (expectedBuffer.length !== res.text.length) {
                throw new Error("expected len: " + expectedBuffer.length + " received len: " + res.text.length);
            }
            if (expectedBuffer.toString() !== res.text) {
                throw new Error("received buffer differs from expected buffer");
            }
        })
        .end(done);
    });

});
