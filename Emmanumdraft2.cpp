#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class binary{

public:
	int num;
	int numover;
	int decimal();
	binary operator= (int);#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class binary{

public:
	int num;
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
	if (b.strnum.length()>10){
		string x = b.strnum.substr(b.strnum.length()-10);
		string y = b.strnum.substr(0,b.strnum.length()-10);
		b.num = atoi(x.c_str());
		b.numover = atoi(y.c_str());
	}
	else {
		b.num = atoi(b.strnum.c_str());
		b.numover=0;
	}
}

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

int binary::addbi(int add1,int add2,int overadd1,int overadd2,)
{
	int digit1=0,digit2=0,danswer=0,answer=0,carry=0;
	int column = 1;
	while (add1>0 or add2>0 or carry>0){
		//cout<<endl<<"new add 1 add2 "<<add1<<" "<<add2<<endl;
		if (add1%2==1){
			digit1 = 1;
			add1 -= 1;
		}
		add1 /= 10;
		if (add2%2==1){
			digit2 = 1;
			add2 -= 1;
		}
		add2 /= 10;
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
		answer += column*danswer;
		//cout<<"digits "<<digit1<<digit2<<endl;
		//cout<<"danswer "<<danswer<<endl;
		//cout<<"carry "<<carry<<endl;
		column *= 10;
		digit1 = 0,digit2 = 0,danswer = 0;
	}
	cout<<"answer "<<answer<<endl;
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
	int add1 = num;
	int add2 = twonum.num;
	int overadd1 = numover;
	int overadd2 = twonum.numover;
	cout<<"add1 "<<add1<<" add2 "<<add2<<endl;
	binary sum;
	sum.num = addbi(add1,add2,overadd1,overadd2);
	return sum;
};

int main(){
	
	int a = 1000000000;
	float b = 10;
	cout<<a<<endl;
	cout<<sizeof(int)<<endl;
	cout<<sizeof(long)<<endl;
	cout<<sizeof(float)<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;
	cout<<b<<endl;

	string check = "abcdefgh";
	string x = check.substr(check.length()-10);
	string y = check.substr(0,check.length()-10);
	cout<<"x "<<x<<endl;
	cout<<"y "<<y<<endl;	



	/*
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
	*/
}
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
	co<<b.num;
	return co;
}

istream& operator>> (istream& ci, binary& b)
{
	string check;
	ci >> check;
	if (check.length()>10){
		string x = check.substr(check.length()-10);
		string y = check.substr(0,check.length()-10);
		b.num = atoi(x.c_str());
		b.numover = atoi(y.c_str());
	}
	else {
		b.num = atoi(check.c_str());
		b.numover=0;
	}
	return ci;
}
int binary::addbi(int add1,int add2,int overadd1,int overadd2,)
{
	int digit1=0,digit2=0,danswer=0,answer=0,carry=0;
	int column = 1;
	while (add1>0 or add2>0 or carry>0){
		//cout<<endl<<"new add 1 add2 "<<add1<<" "<<add2<<endl;
		if (add1%2==1){
			digit1 = 1;
			add1 -= 1;
		}
		add1 /= 10;
		if (add2%2==1){
			digit2 = 1;
			add2 -= 1;
		}
		add2 /= 10;
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
		answer += column*danswer;
		//cout<<"digits "<<digit1<<digit2<<endl;
		//cout<<"danswer "<<danswer<<endl;
		//cout<<"carry "<<carry<<endl;
		column *= 10;
		digit1 = 0,digit2 = 0,danswer = 0;
	}
	cout<<"answer "<<answer<<endl;
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
	int add1 = num;
	int add2 = twonum.num;
	int overadd1 = numover;
	int overadd2 = twonum.numover;
	cout<<"add1 "<<add1<<" add2 "<<add2<<endl;
	binary sum;
	sum.num = addbi(add1,add2,overadd1,overadd2);
	return sum;
};

int main(){
	
	int a = 1000000000;
	float b = 10;
	cout<<a<<endl;
	cout<<sizeof(int)<<endl;
	cout<<sizeof(long)<<endl;
	cout<<sizeof(float)<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;
	cout<<b<<endl;

	string check = "abcdefgh";
	string x = check.substr(check.length()-10);
	string y = check.substr(0,check.length()-10);
	cout<<"x "<<x<<endl;
	cout<<"y "<<y<<endl;	



	/*
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
	*/
}