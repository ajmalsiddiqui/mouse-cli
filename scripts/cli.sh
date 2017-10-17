#!/bin/bash

# This script compiles the cli.cpp file located in the src directory
# TODO: Replace all compile scripts with makefile

if [ ! -d "build" ]; then
    mkdir "build"
fi

wd=`pwd`

g++ -o $wd/build/cli $wd/src/cli.cpp $wd/src/split_delim.cpp $wd/src/man.cpp

if [ $? -eq 0 ]; then
    $wd/build/cli
fi