#!/bin/bash

#$1 indicates the second parameter passed during running the program
no1=$1
no2=$2
counter=1

while [ $counter -lt 10 ]
	do
	echo $no2
	temp=$no2
	no2=$(($no1 + $no2))
	no1=$temp
	counter=$(($counter + 1))
done
