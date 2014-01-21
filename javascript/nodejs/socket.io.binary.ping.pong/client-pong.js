var socket = null;

function start() {
    console.log('start');
    socket = io.connect();
    console.log('created socket' + socket);

    socket.on('ping', function (data) {
        socket.emit('pong', data);
    });
}
