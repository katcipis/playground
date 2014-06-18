"use strict";

var request = require('supertest');
var express = require('express');


var app = express();
var expectedBuffer = new Buffer(10);

var getRandomFloat = function(min, max) {
  return Math.random() * (max - min + 1) + min;
}
var getRandomInt = function (min, max) {
  return Math.floor(getRandomFloat(min,max));
}

for (var i = 0; i < expectedBuffer.length; i++) {
    expectedBuffer[i] = getRandomInt(0,255);
}

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
            console.log(res);
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
