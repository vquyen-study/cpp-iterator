#! /usr/bin/bash

cd src

echo "------------------------ CFG ------------------------"
cmake -S . -B build
echo 
echo 
echo 
echo 
echo 

echo "------------------------ BLD ------------------------"
cmake --build build

echo 
echo 
echo 
echo 
echo 
echo "------------------------ RUN ------------------------"

build/iter

# cd -

