#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>

using namespace std;

class binary{

public:
	int num;
	int numlist[];
	int numover;
	string strnum;
	binary chop(binary);
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
	int bin = num;
	int dec = 0;
	int column = 1;
	while (bin>0){
		dec += column*(bin%2);
		bin /=10;
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
	return ci;
}

binary binary::chop(binary b)
{
	b.numlist[b.strnum.length()];
	for (int i = 0; i < b.strnum.length(); ++i)
	{
		const char* t = &b.strnum[i];
		b.numlist[i] = atoi(t);
	}
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
int binary::addbi(int add1[],int add2[])
{
	int digit1=0,digit2=0,danswer=0,carry=0;
	if (add1.length()>=add2.length()){
		int answer[add1.length()+1];
	}
	else {int answer[add2.length()+1];}

	answer[0] = 0;
	int column = 1;
	int one = add1.length()-1;
	int two = add2.length()-1;
	int column = answer.length()-1;
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
	
	return answer;
}
binary binary::operator= (int right)
{
	num = right;
}

binary& binary::operator+= (binary right)
{
	int add1 = num;
	cout<<"add1 "<<add1<<endl;
	int add2 = right.num;
	cout<<"add2 "<<add2<<endl;
	num = addbi(add1,add2);
}
binary binary::operator+ (binary twonum)
{
	int add1[] = numlist;
	int add2[] = twonum.numlist;

	cout<<"add1 "<<add1<<" add2 "<<add2<<endl;
	
	int digit1=0,digit2=0,danswer=0,carry=0;
	if (add1.length()>=add2.length()){
		int answer[add1.length()+1];
	}
	else {int answer[add2.length()+1];}

	answer[0] = 0;
	int column = 1;
	int one = add1.length()-1;
	int two = add2.length()-1;
	int column = answer.length()-1;
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

	return sum;
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