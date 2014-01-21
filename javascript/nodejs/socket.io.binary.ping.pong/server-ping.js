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
        console.log("sending data: " + data);
        socket.emit("ping", data);
    });

    var pong_filename = filename + '.pong';
    socket.on("pong", function (data) {
        fs.writeFile(pong_filename, data, function (err) {
            if (err) throw err;
            console.log("\n\nreceived data: " + data);
            console.log(pong_filename + ' is saved!');
        });
    });
});

console.log('Server running at port '+PORT);
