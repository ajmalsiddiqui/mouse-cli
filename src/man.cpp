#include <iostream>
#include <string>

using namespace std;

void man(string command){
    if(command == "add"){
        cout << endl << "Adds two floating point numbers." << endl << endl;
        cout << "Usage:" << endl;
        cout << "add <number_1> <number_2>" << endl;
        cout << "Example:" << endl;
        cout << "add 2.5 3.5" << endl;
        cout << "Result:" << endl;
        cout << "6" << endl << endl;
        return;
    }

    else if(command == "sub"){
        cout << endl << "Subtracts two floating point numbers." << endl << endl;
        cout << "Usage:" << endl;
        cout << "sub <number_1> <number_2>" << endl;
        cout << "Example:" << endl;
        cout << "sub 2.5 3.5" << endl;
        cout << "Result:" << endl;
        cout << "-1" << endl << endl;
        return;
    }

    else if(command == "mul"){
        cout << endl << "Multiplies two floating point numbers." << endl << endl;
        cout << "Usage:" << endl;
        cout << "mul <number_1> <number_2>" << endl;
        cout << "Example:" << endl;
        cout << "mul 2.5 3.5" << endl;
        cout << "Result:" << endl;
        cout << "8.75" << endl << endl;
        return;
    }

    else if(command == "div"){
        cout << endl << "Divides two floating point numbers. Error is thrown if second number is zero." << endl << endl;
        cout << "Usage:" << endl;
        cout << "div <number_1> <number_2>" << endl;
        cout << "Example 1:" << endl;
        cout << "div 2.5 3.5" << endl;
        cout << "Result:" << endl;
        cout << "0.714286" << endl;
        cout << "Example 2:" << endl;
        cout << "div 2.5 0" << endl;
        cout << "Result:" << endl;
        cout << "Error: Cannot divide be zero" << endl << endl;
        return;
    }

    //default case
    else {
        cout << endl << "This command does not exist" << endl << endl;
        return;
    }
}

/*int main(){
    man("mul");
    return 0;
}*/