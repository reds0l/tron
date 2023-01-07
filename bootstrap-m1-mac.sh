#! /bin/bash

# Need to have xquartz installed on mac
# In XQuartz preferences enable "allow connections from network clients"

export HOSTNAME='127.0.0.1'
xhost + ${HOSTNAME}

# Run "docker-compose build" then "docker-compose up" 
# or the start.sh script to start the game