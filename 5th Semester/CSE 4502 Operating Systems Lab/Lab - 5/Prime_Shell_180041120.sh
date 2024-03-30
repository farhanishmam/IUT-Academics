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

#Special Case-1
for i in "${array[@]}";
do
	((count=$count+1))
	if ! [[ $i =~ ^[0-9]+$ ]]
	then 
		echo Please enter an integer instead of $i
		read array[$count-1]
	fi
done

#Special Case-2
if [[ $count == 0 ]]
then
	echo Array is Empty. Please enter a new set of numbers.
	echo Number of elements in your array:
		read count
	echo Enter the elements in the array:
	array=()
	for(( k=0;k<$count;k++ ))
	do
		read val
		array+=( $val )
	done
fi

quicksort 0 $((count-1)) array

prime_arr=()
non_prime_arr=()

for i in "${array[@]}"
do
    nonp_check=0
    for((j=2; j<i; j++))
    do
        if [ $((i%j)) -eq 0 ]
        then
            nonp_check=1
            non_prime_arr+=( $i )
            break
        fi
    done
    if [ $nonp_check -eq 0 ]
    then
        prime_arr+=( $i )
    fi
done

prime_len=${#prime_arr[*]}
non_prime_len=${#non_prime_arr[*]}

echo Sorted prime array elements after are :
for((i=0;i<prime_len;i++))
do
	echo ${prime_arr[$i]}
done

echo Sorted non-prime array elements after are :
for((i=0;i<non_prime_len;i++))
do
	echo ${non_prime_arr[$i]}
done