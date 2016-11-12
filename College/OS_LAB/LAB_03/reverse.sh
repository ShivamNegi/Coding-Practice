#!/bin/bash

echo "Enter a number"
read n
sd=0
rev=1

until [ $n -eq 0 ]
do
    sd=$(( $n % 10 ))
    rev=$(($rev * 10 + $sd))
    n=$(( $n / 10 ))
done

echo "Reverse number of entered digit is ${rev:1}"
