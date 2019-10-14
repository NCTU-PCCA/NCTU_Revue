#! /bin/bash

g++ $1.cpp -o $1.out -O2

time ./$1.out < NCPC17final/input/Problem$1.in > output.out
diff NCPC17final/output/Problem$1.out output.out > result

len=$(cat result | wc -l)
if [ $len -eq 0 ]; then
    echo AC!
else
    echo WA!
fi

rm result
rm output.out
rm $1.out
