#!/bin/bash

LOCATION=$(pwd)

echo "#run led program on startup">>~/.bashrc
(echo "cd" + $LOCATION)>>~/.bashrc
(echo "sudo ./file_to_leds.sh")>>~/.bashrc

