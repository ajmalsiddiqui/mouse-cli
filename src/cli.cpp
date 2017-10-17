/*
** TODO: Add error handling for invalid commands and arguments
** TODO: Fix bugs: no argument commands
*/

#include <iostream>
#include <stack>
#include <string>

#include "split_delim.h"
#include "man.h"

using namespace std;

stack <string> commandStack;
stack <string> bufferStack;

void cli() {
    cout << endl << "Welcome to the demonstration CLI." << endl 
        << "Currently the following arithmetic commands are supported:" << endl 
        << "1. add\n2. sub\n3. mul\n4. div" << endl 
        << "Use man <command> to learn more about a specific command." << endl
        << "\'exit\' for exiting the CLI." << endl << endl;

    string prompt = "-> ";
    
    string command;
    //string * args; 
    
    /*The infinite loop that runs the CLI. It is terminated when the exit command is given*/;
    while(true) {

        cout << prompt;
        
        getline(cin, command);
        commandStack.push(command);

        //free this
        string * args = splitDelimit(command, ' ');

        cout << args[0];

        //handle exit command
        if(args[0] == "exit") {
            cout << prompt << "Exiting CLI..." << endl;
            return;
        }

        //handle set prompt
        // BUGGED
        else if(args[0] == "set-prompt"){
            cout << args[1] << endl;
            prompt = args[1] + " ";
            continue;
        }

        //handle man command
        else if(args[0] ==  "man"){
            man(args[1]);
            continue;
        }
        
        //arithmetic commands
        else if(args[0] == "add") {
            cout << prompt << stof(args[1]) + stof(args[2]) << endl;
            continue;
        }

        else if(args[0] == "sub") {
            cout << prompt << stof(args[1]) - stof(args[2]) << endl;
            continue;
        }

        else if(args[0] == "mul") {
            cout << prompt << stof(args[1]) * stof(args[2]) << endl;
            continue;
        }

        else if(args[0] == "div") {
            if(stof(args[2]) == 0){
                cout << prompt << "Error: Cannot divide be zero" << endl;
                continue;
            }
            cout << prompt << stof(args[1]) / stof(args[2]) << endl;
            continue;
        }

        else {
            cout << prompt << "Invalid command." << endl;
            continue;
        }

    }
}

/*int main() {
    cli();
    return 0;
}*/