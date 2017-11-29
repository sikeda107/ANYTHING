#!/bin/bash
echo "Please input execute number of times:"
read number
echo "number is $number."

for (( i = 0; i < $number; i++ )); do
    #something command
    #./HOGE < hoge.txt 
    echo "$i th"
done
echo "Finish!!"
