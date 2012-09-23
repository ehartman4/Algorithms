#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
	string funtimes = "a3";
	cout<<"giterdone";
	int a = atoi(funtimes.substr(1,1).c_str());
	cout<<a*3;
}