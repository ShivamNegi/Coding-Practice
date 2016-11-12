#!/bin/bash

echo enter the no
read no

cpno=$(($no))
res=0

while [ $no -gt 0 ]
	do
	res=$(($res * 10 + $no % 10))
	no=$(($no / 10))
done


if [ $cpno -eq $res ]
then
	echo palindrome
else
	echo not palindrome
fi
