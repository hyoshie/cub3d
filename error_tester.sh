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
leaklog=leak.log
tmplog=tmp.log

check_leak() {
	grep "All heap blocks were freed" $tmplog > /dev/null
	if [ $? -eq 1 ]; then
		printf $RED"Leak Detected!!\n"$RESET
		echo "$1"
	fi
}

store_leaklog() {
	echo "file name: $1" >> $leaklog
	cat $tmplog >> $leaklog
	echo >> $leaklog
}

print_usage() {
	echo "Usage:"
	echo "./error_teseter.sh [no args and no option]"
	echo "	check error-maps simply."
	echo "	result is test.log"
	echo "./error_teseter.sh --leak [no args]"
	echo "	check error-maps using valgrind"
	echo "	result is leak.log"
}

##### Main Process #####
make
rm -f $testlog $leaklog $tmplog

if [ $# -eq 0 ]; then
	for testmap in ./map/error/*; do
		echo "file name: $testmap" >> $testlog
		./cub3D $testmap 2>> $testlog
		echo >> $testlog
	done
elif [ "$1" = "--leak" ]; then
	for testmap in ./map/error/*; do
		valgrind --leak-check=full --show-leak-kinds=all ./cub3D $testmap 2> $tmplog
		check_leak $testmap
		store_leaklog $testmap
	done
else
	print_usage
fi
rm -f tmp.log
