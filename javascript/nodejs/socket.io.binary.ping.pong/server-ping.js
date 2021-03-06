var express = require('express'),
    app = express(),
    server = require('http').createServer(app),
    io = require('socket.io').listen(server),
    http = require('http'), 
    fs = require('fs'),
    filename = process.argv[2],
    PORT = 8080;

if (!filename) {
    throw Error("Must specify the file to be sent on the ping/pong");
}

server.listen(PORT);

app.get('/', function(req, res) {
    res.sendfile(__dirname + '/index.html');
});

app.use(function(req, res, next){
    res.sendfile(__dirname + req.url);
});

io.sockets.on('connection', function (socket) {
    console.log("sending file:  " + filename);

    fs.readFile(filename, function (err, data) {
        if (err) throw err;
        socket.emit("ping", data);
    });

    var pong_filename = filename + '.pong';
    socket.on("pong", function (data) {
        var buffer = new Buffer(data.length);
        for (var i=0; i < data.length; i++) {
            buffer.writeUInt8(data[i], i);
        }
        fs.writeFile(pong_filename, buffer, function (err) {
            if (err) throw err;
            console.log(pong_filename + ' is saved!');
            socket.disconnect();
        });
    });
});

io.set('log level', 1);
console.log('Server running at port '+PORT);
