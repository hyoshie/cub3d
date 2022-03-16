#!/bin/bash

BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
RESET="\033[0m"

testlog=test.log

##### Main Process #####
make
rm -f $testlog $leaklog $tmplog

if [ $# -eq 0 ]; then
	for testmap in ./map/error/*; do
		echo "file name: $testmap" >> $testlog
		./cub3D $testmap 2>> $testlog
		echo >> $testlog
	done
fi
rm -f tmp.log
