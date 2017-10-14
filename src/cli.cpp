#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <string> commandStack;
stack <string> bufferStack;

void man(string command) {
    
}

void cli() {
    cout << "Welcome to the demonstration CLI." << endl 
        << "Currently the following arithmetic commands are supported:" << endl 
        << "1. add\n2. sub\n3. mul\n4. div" << endl 
        << "Use man <command> to learn more about a specific command." << endl
        << "\'exit\' for exiting the CLI." << endl;
    
        /*The infinite loop that runs the CLI. It is terminated when the exit command is given*/;
    while(true) {
        string command;
        getline(cin, command);
        commandStack.push(command);
        /*
        * TODO: Add CLI logic here
        **/
    }
}

int main() {
    cli();
    return 0;
}