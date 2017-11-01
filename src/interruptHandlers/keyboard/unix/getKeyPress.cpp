#include <iostream>
#include <string>
#include <ncurses.h>
#include <term.h>

using namespace std;

// Function to get (unique) keypress from terminal
int getKeyPress() {

    /*
    * On a linux system, you can modify terminal behaviour using the stty command
    * By default, terminal buffers input until enter is pressed
    * use system call to make terminal send all keystrokes directly to stdin
    **/
    system ("/bin/stty raw");
    /*int first, second, third;
    first = getchar();*/
	
//filter();
    /*SCREEN *s = newterm(NULL, stdin, stdout);
    if (s == 0)
        return(-1);
    //cbreak();
	//filter();
	//initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);*/
    
    int first, second, third;
    first = getchar();
    /*
    * Check for enter key (13) and Ctrl + C (3)
    */
    if(first == 13 || first == 3) {
        //return terminal input behaviour to normal
        system ("/bin/stty cooked");
        endwin();
        return first;
    }

    if(first == 27){
        second = getchar();
        third = getchar();
        //return terminal input behaviour to normal
        system ("/bin/stty cooked");
        //endwin();
        //codes for up arrow and down arrow are 27 91 65 and 27 91 66
        if(third != 65 && third != 66) return -1;
        return third;
    }
    else {
        //if the key pressed is not enter, ctrl + c, up arrow or down arrow, write normal characters to output
        //cout << prompt << " ";
        //putchar(first);
        //endwin();
        system ("/bin/stty cooked");
        return first;
    }

    endwin();
    
}

/*int main(){
    int kp = getKeyPress("-> ");
    cout << kp;
    return 0;
}*/
