var http = require('http');

var getStream = function () {
    var req = http.get({
        hostname: 'localhost', 
        port: 8606,
        path: '/',
        method: 'GET',
        agent:false
    }, function(res) {
        res.on('end', function(chunk) {
            getStream();
        });
        res.on('data', function(chunk) {
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
