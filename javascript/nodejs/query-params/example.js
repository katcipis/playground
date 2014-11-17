var url = require('url');

var example = "http://127.0.0.1:44846/vad/5cae0e55-522c-4d80-8eac-7fe30dc45d80?findSpikes=false&powerDetectionThreshold=0&varianceDetectionThreshold=0";
var queryObject = url.parse(example,true).query;

console.log(JSON.stringify(queryObject));
