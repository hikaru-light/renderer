#!/bin/sh

read -p "Enter compiler version :           " ver

case "$ver" in
	"7") g++-7 -fopenmp main.cpp
			 echo "Compiled!\n"
			 break;;
	"8") g++-8 -fopenmp main.cpp
			 echo "Compiled!\n"
			 break;;
esac

./a.out

