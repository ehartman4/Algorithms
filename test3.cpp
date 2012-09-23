#include <iostream>
#include <bitset>

using namespace std;

int main(){
	bitset<3> fred;
	fred[1] = 1;
	cout<<fred<<endl;
	bitset<3> george;
	george[0] = 1;
	george[2] = 1;
	cout<<george<<endl;
	fred = george;
	cout<<fred<<endl;
}