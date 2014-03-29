"use strict";

var chai = require('chai'),
expect = chai.expect,
request = require('supertest'),
express = require('express');


var stream = []
var streamer = {
    onData : function(callback) {
        stream.forEach(function(data) {
            callback(data.data, data.done);
        });
    },
    injectData : function(data, done) {
        stream.push({data:data, done:done});
    }
}

var app = express();

app.get('/',  function(req, res) {
    streamer.onData(function (data, done) {
        if (done) {
            res.end(data);
            return;
        }
        res.write(data);
    });
});

describe('Streaming data test', function() {

    var getRandomFloat = function(min, max) {
      return Math.random() * (max - min + 1) + min;
    }

    var getRandomInt = function (min, max) {
        return Math.floor(getRandomFloat(min,max));
    }

    var createResponseChunks = function (amountOfBuffers) {
        var buffers = [];

        for (var i = 0; i < amountOfBuffers; i++) {
            var buffer_size = getRandomInt(64, 512);
            var buffer = new Buffer(buffer_size);
            for (var j = 0; j < buffer_size; j++) {
                buffer[j] = getRandomInt(0, 255);
            }
            buffers.push(buffer);
        }
        return {body : Buffer.concat(buffers), buffers : buffers}
    }

    var streamData = function(chunk, done) {
        streamer.injectData(chunk, done);  
    }

    var expectAllStreamToBeSent = function (responseBody, done) {
        request(app)
        .get('/')
        .expect(200)
        .expect(function(res) {
            expect(res).to.exist;
            expect(res.text).to.exist;
            expect(responseBody.toString().length).to.equal(res.text.length);
            expect(responseBody.toString()).to.equal(res.text);
        })
        .end(done);
    }

    it('should send all chunks correctly', function(done) {
        var amountOfChunks = 3;
        var responseBody = createResponseChunks(amountOfChunks);

        expectAllStreamToBeSent(responseBody.body, done);
        streamData(responseBody.buffers[0]);
        streamData(responseBody.buffers[1]);
        streamData(responseBody.buffers[2], true);
    });

});
