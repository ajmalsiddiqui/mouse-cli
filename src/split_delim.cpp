#include <iostream>
#include <string>
#include <vector>

using namespace std;

string * splitDelimit(string toSplit, char delimiter) {
    vector<string> delimitedArrayVector;
    string temp;

    for(int i=0; i<toSplit.length(); i++) {
        if(toSplit[i] == delimiter) {
            delimitedArrayVector.push_back(temp);
            temp = "";
        }
        else {
            temp += toSplit[i];
            if(i == toSplit.length() - 1){
                delimitedArrayVector.push_back(temp);
                break;
            }
        }
    }

    string * delimitedArray = (string *) malloc(delimitedArrayVector.size() * sizeof(string));

    for(int i=0; i<delimitedArrayVector.size(); i++) 
        delimitedArray[i] = delimitedArrayVector[i];
    
    return delimitedArray;
}

/*int main(){
    string test = "hello world, this is, Ajmal";

    //vector<string> * res;
    string * res;
    res = splitDelimit(test, ' ');
    cout << res[0] << endl << res[1];
    //cout << res[0] << endl << res[1];

    return 0;
}*/