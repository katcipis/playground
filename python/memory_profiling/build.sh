#!/usr/bin/env bash
set -o errexit

if [ "$EUID" -ne 0 ]; then
    echo "This script uses functionality which requires root privileges"
    exit 1
fi

# Start the build with an empty ACI
acbuild --debug begin

# In the event of the script exiting, end the build
trap "{ export EXT=$?; acbuild --debug end && exit $EXT; }" EXIT

# Name the ACI
acbuild --debug set-name generators

# Based on alpine
acbuild --debug dep add quay.io/coreos/alpine-sh

# Install nodejs
acbuild --debug run -- apk update
acbuild --debug run -- apk add --no-cache python3-dev
acbuild --debug run -- python3 -m ensurepip
acbuild --debug run -- pip3 install --upgrade pip setuptools
acbuild --debug run -- pip install --upgrade memory_profiler

# Copy the app to the ACI
acbuild --debug copy generators.py /generators/main.py

# Run main.py with the app
acbuild --debug set-exec -- /usr/bin/python3 /generators/main.py

# Write the result
acbuild --debug write --overwrite generators-amd64.aci
