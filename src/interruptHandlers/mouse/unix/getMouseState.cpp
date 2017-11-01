#include<iostream>
#include<string>

using namespace std;

int getMouseState(){
	int status1 = system("xinput --query-state 12 | grep -iq \"button\\[1\\]=down\"");
	int status2 = system("xinput --query-state 12 | grep -iq \"button\\[2\\]=down\"");
	if(status1 == 0) return 1;
	else if(status2 == 0) return 2;
	return 0;
}

/*int main(){
	int x = getMouseState();
	cout << x;
}*/
	
