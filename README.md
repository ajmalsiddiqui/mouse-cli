# CLI With Mouse Interrupt Handling

#### Currently in development

### Contents:

1. [Description](#description)
2. [Current Progress](#current-progress)
3. [Instructions for Use](#instructions-for-use)
    - [Windows](#windows)
    - [Linux or Mac OSX](#linux-or-mac-osx)
4. [To Do](#to-do)

### Description:

A simple mock CLI that is intended to respond to mouse interrupts in addition to keyboard interrupts.

### Current Progress:

The basic CLI is working. Bug fixes and error handling are yet to be completed.

### Instructions for Use:

#### Windows: 

Currently no makefiles exist for this project. And unfortunately no script has been written to compile and link the code. In order to run this, compile the following files using your favourite compiler and preferably output the executable into the build directory:

- main.cpp
- src/cli.cpp
- src/split_delimit.cpp
- src/man.cpp

An example of doing this from the root directory using g++ is:
    `g++ -o build/main src/cli.cpp src/split_delim.cpp src/man.cpp main.cpp`

In order to run this, execute:
    `build/main`

#### Linux or Mac OSX:

The above mentioned [steps for windows](#windows) can be followed for Linux/Mac OSX too. But an easier way to compile and run the main file is to execute the following script:
    `bash scripts/main.sh`

### To Do:

1. Write a makefile
2. Error handling for invalid commands and arguments
3. Interrupt handling


