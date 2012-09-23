#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

class binary{

public:
	int num;
	int numlist[];
	int numlength;
	int numover;
	int size;
	string strnum;
	binary chop();
	binary dechop(binary);
	int decimal();
	binary back();
	binary operator= (int);
	binary operator+ (binary);
	binary& operator+= (binary);
	int addbi(int,int);
	friend ostream& operator<< (ostream&, binary);
	friend istream& operator>> (istream&, binary&);

};

int binary::decimal()
{
	int bin = strnum.length()-1;
	int dec = 0;
	int column = 1;
	int a;
	string g;
	const char* t;
	while (bin>=0){
		g = strnum[bin];
		a = atoi(g.c_str());
		dec += column*a;
		bin -= 1;
		column *= 2;
	}
	return dec;
}

binary binary::back(int input)
{
	str next;
	int input = input;
	if (input%2==1){
		next = '1'
	}
}
ostream& operator<< (ostream& co, binary b)
{
	co<<b.strnum;
	return co;
}

istream& operator>> (istream& ci, binary& b)
{
	ci >> b.strnum;
	//b.chop();
	return ci;
}

binary binary::chop()
{
	numlist[strnum.length()];
	for (int i = 0; i < strnum.length(); ++i)
	{
		const char* t = &strnum[i];
		numlist[i] = atoi(t);
	}
	size = strnum.length();
}
/*
binary binary::dechop(binary b)
{
	if (b.numover>10){
		b.strnum = string x = strnum.substr(strnum.length()-10);
		string y = strnum.substr(0,strnum.length()-10);
		b.num = atoi(x.c_str());
		b.numover = atoi(y.c_str());
	}
	else {
		b.num = atoi(strnum.c_str());
		b.numover=0;
	}
}
*/


binary binary::operator= (int right)
{
	num = right;
}


binary& binary::operator+= (binary right)
{
	int one = decimal();
	int two = right.decimal();
	num = one + two;
	
}
binary binary::operator+ (binary twonum)
{
	int one = decimal();
	int two = twonum.decimal();
	binary sum;
	int three = one + two;
	sum.num = three;
	return sum;

};

int main(){

	
	binary one,two;
	cin >>one;
	cin>>two;
	cout<<one<<endl;
	cout<<one.decimal()<<endl;
	/*
	binary three = one+two;
	cout<<"three: "<<three<<endl;
	cout<<"three+two: "<<three+two<<endl;
	three +=two;
	cout<<"new three: "<<three<<endl;
	one = one + two;
	cout<<"one"<<one<<endl;
	cout<<two<<" equals "<<two.decimal()<<endl;
	*/
}