/*
* TODO: Add error handling for invalid commands and arguments
* TODO: Fix bugs: no argument commands
* TODO: fix indentation bug
* TODO: Fix exit bug
**/

#include <iostream>
#include <stack>
#include <string>

#include <pthread.h>

//include the OS specific interrupt handler
//_WIN32 is defined for both windows 64 bit and 32 bit
#if defined(_WIN32)
    // TODO: write the handlers for windows
//if not windows, then assume unix
#else
    #include "interruptHandlers/keyboard/unix/getKeyPress.h"
	#include "interruptHandlers/mouse/unix/getMouseState.h"
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
	exit(0);
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

	//system commands
	else if(args[0] == "sys"){
		if(args[1] == "null"){
			cout << prompt << "Error: no command supplied" << endl;
			return;
		}
		else if(args[2] == "null") {
			system(args[1].c_str());
			return;
		}
		else {
			system((args[1] + " " + args[2]).c_str());
			return;
		}
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
        //handleCommand("exit");
        cout << "Exiting CLI..." << endl;
        continueFlag = false;
        exit(0);
        return "null";
    }
    //Up arrow
    else if(code == 65) {
        //cout << "dummy";
        //ensure command stack is not empty
        //cout << "up" << endl;
        /*if(!commandStack.empty()) {
            string tempCommand = commandStack.top();
            commandStack.pop();
            bufferStack.push(tempCommand);
            return tempCommand;
        }
        else {
            return "";
        }*/
        if(!commandStack.empty())
            return commandStack.top();
        return "$";
        //return "add 2 3";
    }
    //down arrow
    else if(code == 66) {
        //cout << "dummyd";
        //ensure bufferstack is not empty
        //cout << "down" << endl;
        /*if(!bufferStack.empty()) {
            string tempCommand = bufferStack.top();
            bufferStack.pop();
            commandStack.push(tempCommand);
            return tempCommand;
        }
        else {
            return "";
        }*/
        //return "div 3 0";
        return "$";
    }
    else {
        //cout << (char) code;
        return "$";
    }
}

string handleMouse(int code){
	if(code == 1) {
		// enter key pressed ;)
		return "ent";
		
	}
	else if(code == 2) {
		// ctrl + c
		cout << prompt << "Exiting CLI..." << endl;
		continueFlag = false;
		exit(0);
		return "end";
	}
	else return "$";
}

void *mouseLoop(void *vargp){
	while(1){
		int mc = getMouseState();
		//cout << mc << endl;
		
		if(mc == 1) {
			system("/bin/stty cooked");
			cout << "Exiting CLI..." << endl;
			exit(0);
		}
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

	//p thread that looks for mouse interrupt
	pthread_t tid;
	pthread_create(&tid, NULL, mouseLoop, NULL);
    
    /*The infinite loop that runs the CLI. It is terminated when the exit command is given*/;
    while(continueFlag) {

        cout << prompt;

	//int mc = getMouseState();
	//string mouse = handleMouse(mc);

        int kp = getKeyPress();
        //cout << kp << endl;

        string handle = handleKey(kp);
        //cout << "hello" << endl;

        if(handle == "$") getline(cin, command);
        
        command = handle != "$" ? handle : (char)kp + command;
        if(handle != "$") cout << command;

        //only check for enter key press if command history is being used
        int checkEnter = handle == "$" ? 13 : getKeyPress();
	//if(handleMouse(mc) == "ent") checkEnter = 13;
        cout << ((handle != "$") ? "\n" : "");


        //code for enter key
        if(checkEnter == 13){
            //cout << "enter" << endl;
            commandStack.push(command);
            
            //free this
            string * args = splitDelimit(command, ' ');
	
	    if(stoi(args[3]) == 3)
            	handleCommand(args[0], args[1], args[2]);
	    else if(stoi(args[3]) == 2)
		handleCommand(args[0], args[1], "null");
	    else
		handleCommand(args[0], "null", "null");

            //free(args);
        }

    }

    return;
}

/*int main() {
    cli();
    return 0;
}*/
