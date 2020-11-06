#! /bin/bash

g++ gen.cpp -o gen
./gen > input.in
time ./a.out < input.in
