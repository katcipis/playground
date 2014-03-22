var cmdName = process.argv[2],
spawn = require('child_process').spawn;

if (!cmdName) {
    throw "Error: must inform process name";
}

var cmd = spawn(cmdName);

cmd.on('error', function (err) {
    console.log('Error executing process: ' + err);
});

cmd.on('exit', function () {
    console.log('process exited');
});

