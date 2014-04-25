"use strict";

var chai = require('chai'),
expect = chai.expect,
request = require('supertest'),
express = require('express');


var app = express();
var expectedBuffer = new Buffer(1048576);

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
    res.write(expectedBuffer.slice(0, expectedBuffer.length/2));
    res.write(expectedBuffer.slice(expectedBuffer.length/2));
    res.end();
});

describe('Streaming data test', function() {

    it('should send all data correctly', function(done) {
        request(app)
        .get('/')
        .expect(200)
        .expect(function(res) {
            expect(res).to.exist;
            expect(res.text).to.exist;
            expect(expectedBuffer.toString().length).to.equal(res.text.length);
            expect(expectedBuffer.toString()).to.equal(res.text);
        })
        .end(done);
    });

});
