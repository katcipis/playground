#!/bin/sh

while true; do
    mocha streamed-response-tests.js
    if [ $? != 0 ] ; then
        exit 
    fi
done
