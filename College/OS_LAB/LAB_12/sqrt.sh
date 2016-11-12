#!/bin/bash

flag=1
while [ $flag -eq 1 ]
    do
    echo Enter the number
    read no1
    calc=$(echo "sqrt($no1)" | bc)
    sqno=$(($calc * $calc))
    if [ $no1 -eq $sqno ]
      then
        flag=0
    else
        flag=1
    fi
done
