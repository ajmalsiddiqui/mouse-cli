#include <iostream>
#include <string>
#include <vector>

using namespace std;

string * splitDelimit(string toSplit, char delimiter) {
    vector<string> delimitedArrayVector;
    string temp;

    for(int i=0; i<toSplit.length(); i++) {
        if(toSplit[i] == delimiter) {
	    if(i == toSplit.length() - 1) break;
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

    //string * delimitedArray = (string *) malloc((delimitedArrayVector.size() + 1)* sizeof(string));

    string * delimitedArray = (string *) malloc(4* sizeof(string));
    for(int i=0; i<delimitedArrayVector.size(); i++) 
        delimitedArray[i] = delimitedArrayVector[i];
	// in this use case, each command has length 3, so the 4th element can store the size
	delimitedArray[3] = to_string(delimitedArrayVector.size());
    
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
