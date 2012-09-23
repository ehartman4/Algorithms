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
	while (bin>0){
		dec += column*(strnum[bin]);
		cout<<dec<<endl;
		bin -= 1;
		column *= 2;
	}
	return dec;
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

binary binary::back ()
{
	int start = 
	while 
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
	/*
	int add1[size];
	int add2[twonum.size];
	add1 = numlist;
	add2 = twonum.numlist;
	cout<<"add1 "<<add1<<" add2 "<<add2<<endl;
	
	int digit1=0,digit2=0,danswer=0,carry=0;
	if (size>=twonum.size{
		int answer[size+1];
	}
	else {int answer[twonum.size+1];}

	answer[0] = 0;
	int column = 1;
	int one = size-1;
	int two = twonum.size-1;
	int column = (int)answer.size()-1;
	while (one>0 or two>0 or carry>0){
		//cout<<endl<<"new add 1 add2 "<<add1<<" "<<add2<<endl;
		
		if (one>=0 and add1[one]==1){
			digit1 = 1;
		}
		if (two>=0 and add2[two]==1){
			digit2 = 1;
		}
		danswer = digit1+digit2+carry;	
		if (danswer==2){
			danswer=0;
			carry=1;
		}
		else if (danswer==3){
			danswer=1;
			carry=1;
		}
		else{carry=0;}
		answer[column] = danswer;
		//cout<<"digits "<<digit1<<digit2<<endl;
		//cout<<"danswer "<<danswer<<endl;
		//cout<<"carry "<<carry<<endl;
		one -= 1,two -= 1,column -= 1;
		digit1 = 0,digit2 = 0,danswer = 0;
	}
	cout<<"answer "<<endl;
	for (int i = 0; i < answer.length(); ++i)
	{
		cout<<answer[i];
	}
	cout<<endl;
	binary sum;
	sum.numlist=answer;

	return sum;*/

};

int main(){
	/*string funtimes;
	cout<<"giterdone";
	cin.get(funtimes);
	cout<<funtimes;
	*/

	
	binary one,two;
	cin >>one;
	cin>>two;
	binary three = one+two;
	cout<<"three: "<<three<<endl;
	cout<<"three+two: "<<three+two<<endl;
	three +=two;
	cout<<"new three: "<<three<<endl;
	one = one + two;
	cout<<"one"<<one<<endl;
	cout<<two<<" equals "<<two.decimal()<<endl;
	
}