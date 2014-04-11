var http = require('http');

var getStream = function () {
    var req = http.get({
        hostname: 'localhost', 
        port: 7777,
        path: '/',
        method: 'GET',
        agent:false
    }, function(res) {
        res.on('end', function() {
            console.log("received end");
            getStream();
        });
        res.on('data', function(chunk) {
            console.log("received data: " + chunk.length);
        });
    });

}

if (process.argv.length < 3) {
    throw Error("Missing parameters.\n usage: "+process.argv[1]+" <amount of concurrent streams> \n\n");
}

var streamsCount = parseInt(process.argv[2]);
console.log("creating: " + streamsCount + " streams");
for (var i = 0; i < streamsCount; i++) {
    getStream();
}
