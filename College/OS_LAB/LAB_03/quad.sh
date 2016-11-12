#!/bin/bash
echo "enter values of a,b and c"
read a
read b
read c
d=`expr $b \* $b - 4 \* $a \* $c`
if [ $d -eq 0 ]
then
t=0
elif [ $d -gt 0 ]
then
t=1
else
t=2
fi
case $t in
"0") echo `expr -$b / \( 2 \* $a \)`
    ;;
"1") x=$( echo "sqrt ( $d )" | bc )
     res=$(((-$b - $x) / (2 * $a)))
     echo $res
     res=$(((-$b + $x) / (2 * $a)))
     echo $res
     ;;
"2") d=$((- $d))
     x=$( echo "sqrt ( $d )" | bc )
     res1=$(echo "scale=2;(- $b ) / (2 * $a)"|bc)
     res2=$(echo "scale=2;( $x ) / (2 * $a)"|bc)
     echo "$res1 + i $res2"
     echo "$res1 - i $res2"
     ;;
esac
