"use strict";

module.exports.getOctetStream = function() {
    var octetStream = new Buffer(10);
    octetStream[0] = 234;
    octetStream[1] = 235;
    octetStream[2] = 196;
    octetStream[3] = 189;
    octetStream[4] = 10;
    octetStream[5] = 183;
    octetStream[6] = 66;
    octetStream[7] = 150;
    octetStream[8] = 173;
    octetStream[9] = 235;
    return octetStream;
}
