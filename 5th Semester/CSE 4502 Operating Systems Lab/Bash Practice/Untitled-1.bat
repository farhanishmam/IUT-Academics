#echo "Input total limit in the array"
read limit
echo "Input numbers for the array: "
for((i=0;i<limit;i++))
do
read arr[$i]
if ! [[ ${arr[$i]} =~ ^[0-9]+$ ]]
    then
        echo "Integer only"
        i=$i-1
    fi
done
while [[ !" ${arr[@]} " =~ " ${value} " ]]; do
    echo "Array doesn't contain value"
    echo "Input total limit in the array"
    read limit
    echo "Input numbers for the array: "
    for((i=0;i<limit;i++))
    do
    read arr[$i]
    done
done

for((i=0;i<limit;i++))
do
leap=${arr[$i]}
if [ `expr $leap % 400` -eq 0 ]
then
echo the year is leap year
elif [ `expr $leap % 100` -eq 0 ]
then
echo the year is not a leap year
elif [ `expr $leap % 4` -eq 0 ]
then
echo the year is leap year
else
echo the year is not a leap year
fi
done
