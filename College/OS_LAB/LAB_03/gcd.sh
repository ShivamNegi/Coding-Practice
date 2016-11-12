#!/bin/bash

echo enter no1
read no1
echo enter no2
read no2

rem=$(($no1 % $no2))

while [ $rem -gt 0 ]
	do
		no1=$(($no2))
		no2=$(($rem))
		rem=$(($no1 % $no2))
done

echo $no2
