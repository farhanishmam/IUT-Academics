#!/bin/bash
nano testFile.txt #In nano save the file as test1.txt
echo "Enter Destination Location"
read destLoc
mkdir -p "$destLoc"
> "$destdir"/test2.txt
cp test1.txt test.txt

chmod +wx test.txt
chmod +wx test1.txt
chmod +wx "$destdir"/test2.txt
