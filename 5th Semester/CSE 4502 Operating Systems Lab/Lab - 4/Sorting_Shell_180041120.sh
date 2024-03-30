#!/bin/bash

function quicksort()
{
	left=$1
	right=$2

	if [[ $1 -lt $2 ]]
	then
		pivot=${array[$1]}
		while(( $left < $right ))
		do
			while((${array[$left]} <= $pivot && $left < $2))
			do
				left=$(($left + 1))
			done
			
			while((${array[$right]} > $pivot))
			do
				right=$(($right-1))
			done

			if [[ $left -lt $right ]]
			then
				temp=${array[$left]}
				array[$left]=${array[$right]}
				array[$right]=$temp
			fi
		done
		temp=${array[$right]}
		array[$right]=${array[$1]}
		array[$1]=$temp
		temp=$right

		quicksort $1 $((right-1)) array
		quicksort $((temp+1)) $2 array
	fi
}

count=0
array=("$@")

#Task-1
for i in "${array[@]}";
do
	((count=$count+1))
	if ! [[ $i =~ ^[0-9]+$ ]]
	then 
		echo Please enter an integer instead of $i
		read array[$count-1]
	fi
done

#Task-2
if [[ $count == 0 ]]
then
	echo Array is Empty. Please enter a new set of numbers.
	echo Number of elements in your array:
	read count
	echo Enter the elements in the array:
	for((i=0;i<$count;i++))
	do
		read array[i]
		if ! [[ ${array[$i]} =~ ^[0-9]+$ ]]
		then 
			echo Please enter the last input as an integer:
			i=$i-1
		fi	
	done
fi

quicksort 0 $((count-1)) array

echo Sorted array elements after are :
for((i=0;i<count;i++))
do
	echo ${array[$i]}
done