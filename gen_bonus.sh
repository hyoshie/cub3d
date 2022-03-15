#/!bin/bash

includeDir=./inc
sourceDir=./src
# bonusDir=./bonus
bonusInculdeDir=./bonus/inc
bonusSourceDir=./bonus/src

###	Make Bonus Directory ###
mkdir -p $bonusInculdeDir
mkdir -p $bonusSourceDir
for dir in $(ls $sourceDir)
do
	mkdir -p $bonusSourceDir/$dir
done
rmdir $bonusSourceDir/main.c

###	Make Bonus Headers ###
for header in $(ls $includeDir)
do
	newFileName=$(echo $header | sed 's/\.h$/_bonus\.h/g')
	cp  $includeDir/$header $bonusInculdeDir/$newFileName
done

###	Make Bonus Source files ###
for src in $(ls $sourceDir/**/*)
do
	newFileName=$(echo $src | sed 's/\.c$/_bonus\.c/g' | sed 's/\.\/src\///g')
	cp $src $bonusSourceDir/$newFileName
done
cp $sourceDir/main.c $bonusSourceDir/main_bonus.c
