/*
* TODO: Add error handling for invalid commands and arguments
* TODO: Fix bugs: no argument commands
* TODO: fix indentation bug
**/

#include <iostream>
#include <stack>
#include <string>

//include the OS specific interrupt handler
//_WIN32 is defined for both windows 64 bit and 32 bit
#if defined(_WIN32)
    // TODO: write the handlers for windows
//if not windows, then assume unix
#else
    #include "interruptHandlers/keyboard/unix/getKeyPress.h"
#endif

#include "split_delim.h"
#include "man.h"

using namespace std;

bool continueFlag = true;

stack <string> commandStack;
stack <string> bufferStack;

string prompt = "-> ";

void handleCommand(string command, string args_1 = "null", string args_2 = "null"){
    string args[3];
    args[0] = command;
    args[1] = args_1;
    args[2] = args_2;

    //handle exit command
    if(args[0] == "exit") {
        cout << prompt << "Exiting CLI..." << endl;
        continueFlag = false;
        return;
    }

    //handle set prompt
    // BUGGED
    else if(args[0] == "set-prompt"){
        cout << args[1] << endl;
        prompt = args[1] + " ";
        return;
    }

    //handle man command
    else if(args[0] ==  "man"){
        man(args[1]);
        return;
    }
    
    //arithmetic commands
    else if(args[0] == "add") {
        cout << prompt << stof(args[1]) + stof(args[2]) << endl;
        return;
    }

    else if(args[0] == "sub") {
        cout << prompt << stof(args[1]) - stof(args[2]) << endl;
        return;
    }

    else if(args[0] == "mul") {
        cout << prompt << stof(args[1]) * stof(args[2]) << endl;
        return;
    }

    else if(args[0] == "div") {
        if(stof(args[2]) == 0){
            cout << prompt << "Error: Cannot divide be zero" << endl;
            return;
        }
        cout << prompt << stof(args[1]) / stof(args[2]) << endl;
        return;
    }

    else {
        cout << prompt << "Invalid command." << endl;
        return;
    }
}

string handleKey(int code){
    // TODO: add command history logic
    //Ctrl + C
    if(code == 3) {
        handleCommand("exit");
        return "null";
    }
    //Up arrow
    else if(code == 65) {
        //cout << "dummy";
        return "add 2 3";
    }
    //down arrow
    else if(code == 66) {
        //cout << "dummyd";
        return "div 3 0";
    }
    else {
        return "\0";
    }
}

void cli() {
    cout << endl << "Welcome to the demonstration CLI." << endl 
        << "Currently the following arithmetic commands are supported:" << endl 
        << "1. add\n2. sub\n3. mul\n4. div" << endl 
        << "Use man <command> to learn more about a specific command." << endl
        << "\'exit\' for exiting the CLI." << endl << endl;
    
    string command = "";
    string * tmp;
    //string * args; 
    
    /*The infinite loop that runs the CLI. It is terminated when the exit command is given*/;
    while(continueFlag) {

        cout << prompt << " ";

        int kp = getKeyPress();
        //cout << kp << endl;

        if(handleKey(kp) == "\0") getline(cin, command);
        
        command = handleKey(kp) != "\0" ? handleKey(kp) : (char)kp + command;
        if(handleKey(kp) != "\0") cout << command;

        //only check for enter key press if command history is being used
        int checkEnter = handleKey(kp) == "\0" ? 13 : getKeyPress();

        //code for enter key
        if(checkEnter == 13){
            cout << "enter" << endl;
            commandStack.push(command);
            
            //free this
            string * args = splitDelimit(command, ' ');
            
            handleCommand(args[0], args[1], args[2]);
        }

    }

    return;
}

/*int main() {
    cli();
    return 0;
}*/