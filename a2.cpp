#include <iostream>
#include <vector>
using namespace std;


class Number{
public:
	string strnum;
	vector<int> bitnum;
	vector<int> chop();
	friend ostream& operator<< (ostream&, Number);
	friend istream& operator>> (istream&, Number&);
	int base;
	Number () {};//empty constructor for binary
	Number (int thebase, vector<int> thebitnum) {base = thebase; bitnum = thebitnum;};
};
istream& operator>> (istream& ci, Number& b)
{
	ci >> b.strnum;
	b.bitnum = b.chop();
	return ci;
}

ostream& operator<< (ostream& co, Number b)
{
	bool it = 0;
	int pos = 19;
	//li<int>::iterator pos;
	//pos = b.bitnum.end();
	// decides whwere to start actually printing out the bitset-style number.
	// For example, 101 is stored as 17 0's and then 101, so it would print out as such. This
	//   finds the first '1' in the number (the largest power of 2 for which there is a '1'),
	//   and starts displaying with this value.
	while (it==0 and pos>0){
		if (b.bitnum[pos]==0){
			pos -=1;
		}
		else{it=1;}
	}
	for (int i = pos; i >=0; --i)
	{
		co<<b.bitnum[i];
	}
	return co;
}

vector<int> Number::chop()
{
	vector<int> innum (20,0);
	// bitsets are stored in revers order, so this takes the last digit in the input string,
	//   which is index [0] in the bitset, and sets it as sch, and so on.
	for (int i = 0; i < strnum.length(); ++i)
	{
		if base==16{
			if (strnum[i] == 'A' or strnum[i] == 'a'){
				innum.push_front(10);}
			else if (strnum[i] == 'B' or strnum[i] == 'b'){
				innum.push_front(11);}
			else if (strnum[i] == 'C' or strnum[i] == 'c'){
				innum.push_front(12);}
			else if (strnum[i] == 'D' or strnum[i] == 'd'):{
				innum.push_front(13);}
			else if (strnum[i] == 'E' or strnum[i] == 'e'):{
				innum.push_front(14);}
			else if (strnum[i] == 'F' or strnum[i] == 'f'):{
				innum.push_front(15);}
			else{innum.push_front(atoi(strnum[i].c_str()));}
			}
		else{}
			innum.push_front(atoi(strnum[i].c_str()));}
		innum.pop_back();
	}
	return inbit;
}

int main(){
	Number three (16,vector<int> neb (20,0));
	cin<<three<<endl;
	cout<<three<<endl;
	return 0;
}