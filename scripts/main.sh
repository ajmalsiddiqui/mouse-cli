#!/bin/bash

# This script compiles the main.cpp file located in the root directory and runs it if compilation is successful
# TODO: Replace all compile scripts with makefile

if [ ! -d "build" ]; then
    mkdir "build"
fi

wd=`pwd`

g++ -o $wd/build/main -std=c++11 $wd/src/cli.cpp $wd/src/split_delim.cpp $wd/src/man.cpp $wd/src/interruptHandlers/keyboard/unix/getKeyPress.cpp $wd/src/interruptHandlers/mouse/unix/getMouseState.cpp $wd/main.cpp -lncurses -lpthread

if [ $? -eq 0 ]; then
    $wd/build/main
fi
