#!/bin/sh
#make
rm test.log
for testmap in ./map/error/*; do
echo "file name: $testmap" >> test.log
./cub3D $testmap 2>> test.log
echo "\n" >> test.log
done