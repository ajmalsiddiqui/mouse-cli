#include <iostream>
#include <string>
#include "split_delim.h"

using namespace std;

int main(){
    string test = "hello world, this is, Ajmal";

    //vector<string> * res;
    string * res;
    res = splitDelimit(test, ' ');
    cout << res[0] << endl << res[1];
    //cout << res[0] << endl << res[1];

    return 0;
}