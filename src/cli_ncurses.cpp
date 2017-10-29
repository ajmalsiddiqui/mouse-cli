#include <iostream>
#include <stack>
#include <string>
#include <string.h>

#include <ncurses.h>
#include <term.h>

//include the OS specific interrupt handler
//_WIN32 is defined for both windows 64 bit and 32 bit
#if defined(_WIN32)
    // TODO: write the handlers for windows
//if not windows, then assume unix
#else
    //#include "interruptHandlers/keyboard/unix/getKeyPress.h"
#endif

#include "split_delim.h"
#include "man.h"

using namespace std;

stack <string> commandStack;
stack <string> bufferStack;

string prompt = "->";

int row, col, x =0, y=0;

int continueFlag = 1;

void newLine(){
    getyx(stdscr, y, x);
    mvcur(x, y, 0, y+1);
    move(y+1,0);
    refresh();
}

void getCommand(char ** command){
    int ch, i=0;
    char temp[10];
    while((ch = getch()) != 10){
        temp[i] = (char)ch;
        putchar(ch);
        refresh();
        i++;
    }
    temp[i] = '\0';
    //printw(temp);
    //refresh();
    *command = &temp[0];
    //strcpy(command, temp);
    //printw(*command);
    //refresh();
    newLine();
    return;
}

void cli() {

    //initialize curses
    initscr();
    //raw();
    cbreak();
    noecho();

    keypad(stdscr, TRUE);

    getmaxyx(stdscr,row,col);
    
    //initialize cli
    printw("Welcome to the demonstration CLI.\nCurrently the following arithmetic commands are supported:\n1. add\n2. sub\n3. mul\n4. div\nUse man <command> to learn more about a specific command.\n\'exit\' for exiting the CLI.\n\n");
    refresh();
    /*while(continueFlag) {

    }*/
    char ** command;
    command = (char **) malloc(10 * sizeof *command);
    getCommand(command);

    // get command
    /*int ch, i=0;
    char temp[10];
    while((ch = getch()) != 10){
        temp[i] = (char)ch;
        putchar(ch);
        refresh();
        i++;
    }
    temp[i] = '\0';*/

    //printw(temp);
    //refresh();
    //command = temp;

    printw((char *)command);
    refresh();
    getch();
	endwin();
}

int main() {
    cli();
    return 0;
}