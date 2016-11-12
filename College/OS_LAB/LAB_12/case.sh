#!/bin/bash

echo enter the characters
read word

case $word in
    123)
        echo Present
        ;;
    *)
        echo Absent
        ;;
esac    