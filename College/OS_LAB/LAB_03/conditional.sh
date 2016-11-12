#!/bin/bash

echo Enter the number to be tested
read no

rem=$((no % 2))

if [ $rem -eq 0 ]
then
echo even
else
echo odd
fi
