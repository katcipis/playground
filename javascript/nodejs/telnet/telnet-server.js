const
port = 5432,
     fs = require('fs'),
     net = require('net'),
     filename = process.argv[2],
     spawn = require('child_process').spawn,
     server = net.createServer(function(connection) {
         console.log('Subscriber connected.');

         connection.on('data', function(data) {
             console.log('received command: ' + data);
             var parsed_cmd = data.toString().trim().split(" ");
             console.log('parsed command: ' + parsed_cmd);
             var cmd_name = parsed_cmd[0];
             var cmd_args = parsed_cmd.slice(1);
             console.log('name: ' + cmd_name + ' args: [' + cmd_args + ']');
             //var cmd = spawn('ls', ['-lh']);
             var cmd = spawn(cmd_name, cmd_args);

             cmd.on('error', function (err) {
                 connection.write('Error executing command: ' + err);
                 connection.write('\n\n');
             });

             cmd.on('exit', function () {
                 console.log('command finished');
                 connection.write('\n\n');
             });

             cmd.stdout.setEncoding('utf8');
             cmd.stdout.on('data', function (stdout_data) {
                 console.log('sending process stdout to client');
                 connection.write(stdout_data);
             });
             cmd.stdout.on('end', function () {
                 console.log('command will provide no more data');
             });
             cmd.stderr.setEncoding('utf8');
             cmd.stderr.on('data', function (err) {
                 console.log('writing process stderr to client');
                 connection.write('Error executing command: ' + err);
             });
         });

         connection.on('close', function() {
             console.log('Subscriber disconnected.');
         });
     });

server.listen(port, function() {
    console.log('Listening for telnet access on port: ' + port);
    console.log('run: telnet <ip> ' + port + ' to access');
});
