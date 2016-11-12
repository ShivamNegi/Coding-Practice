#!/bin/bash

no=2
summ=0

while [ $no -lt 10 ]
	do
	i=2
	lim=$( echo "sqrt ($d)" | bc)
	flag=0
	val=$(($lim - $i))

	while [ $val -gt 0 ]
		do
			if [ $no % $i -eq 0 ]
				then
					flag=1
			fi
			i=$((i + 1))
			val=$(($lim - $i))
		done

	if [ $flag -eq 1 ]
		then
			summ=$(($sum + $no))
	fi
	no=$(($no + 1))
done

echo $summ
