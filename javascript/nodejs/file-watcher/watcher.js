
const fs = require('fs'),
      filename = process.argv[2];

if (!filename) {
    throw Error("Must specify the file to watch");
}

fs.watch(filename, function () {
    console.log("File[" + filename + "] has been changed");
});

console.log("Waiting for changes on [" + filename + "]");
