#include <iostream>

using namespace std;

class binary{
protected:
	int num;
	binary decimal();
public:
	binary operator= (int);
	binary operator+ (binary);
	binary& operator+= (int);
	binary addbi(int,int);
	friend ostream& operator<< (ostream&, binary);
	friend istream& operator>> (istream&, binary&);

};

ostream& operator<< (ostream& co, binary b)
{
	co<<b.num;
	return co;
}

istream& operator>> (istream& ci, binary& b)
{
	ci >> b.num;
	return ci;
}
binary binary::addbi(int add1,int add2)
{
	int digit1=0,digit2=0,danswer=0,answer=0,carry=0,loop=0;
	int column = 1;
	/*
	if carry == 1 {
		if (add1%2==0 and add2%2==0) {
			digit=1;
			carry=0;
		}
		else if (add1%2==1 and add2%2==1) {
			digit=1;
			carry=1;
		}
		else {
			digit=0;
			carry=1;
		}
	}
	else {
		if (add1%2==0 and add2%2==0) {
			digit=0;
			carry=0;
		}
		else if (add1%2==1 and add2%2==1) {
			digit=0;
			carry=1;
		}
		else {
			digit=1;
			carry=0;
		}
	}
	
	answer += (10^loop)*digit;
	loop +=1;*/
	while (add1>0 or add2>0 or carry>0){
		//cout<<endl;
		//cout<<"new add 1 add2 "<<add1<<" "<<add2<<endl;
		if (add1%2==1){//add1 = 101
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
			//cout<<"carry1 "<<carry<<endl;
		}
		
		else if (danswer==3){
			danswer=1;
			carry=1;
			//cout<<"carry2 "<<carry<<endl;
		}
		
		else{
			carry=0;
			//cout<<"carry3 "<<carry<<endl;
		}
		answer += column*danswer;
		column *= 10;
		digit1 = 0,digit2 = 0;
		//cout<<"digits "<<digit1<<digit2<<endl;
		//cout<<"danswer "<<danswer<<endl;
		//cout<<"carry "<<carry<<endl;

		cout<<"answer "<<answer<<endl;
		danswer = 0;

	}
	binary sum;
	sum.num = answer;
	return sum;
}
binary binary::operator= (int right)
{
	num = right;
}

binary& binary::operator+= (int)
{
	cout<<"hey"<<endl;
}
binary binary::operator+ (binary twonum)
{
	int add1 = num;
	cout<<"add1 "<<add1<<endl;
	int add2 = twonum.num;
	cout<<"add2 "<<add2<<endl;
	binary sum = addbi(add1,add2);
	return sum;
	
	//int digit1=0,digit2=0,danswer=0,answer=0,carry=0,loop=0;
	//int column = 1;
	/*
	if carry == 1 {
		if (add1%2==0 and add2%2==0) {
			digit=1;
			carry=0;
		}
		else if (add1%2==1 and add2%2==1) {
			digit=1;
			carry=1;
		}
		else {
			digit=0;
			carry=1;
		}
	}
	else {
		if (add1%2==0 and add2%2==0) {
			digit=0;
			carry=0;
		}
		else if (add1%2==1 and add2%2==1) {
			digit=0;
			carry=1;
		}
		else {
			digit=1;
			carry=0;
		}
	}
	
	answer += (10^loop)*digit;
	loop +=1;*/
	/*
	while (add1>0 or add2>0 or carry>0){
		//cout<<endl;
		//cout<<"new add 1 add2 "<<add1<<" "<<add2<<endl;
		if (add1%2==1){//add1 = 101
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
			//cout<<"carry1 "<<carry<<endl;
		}
		
		else if (danswer==3){
			danswer=1;
			carry=1;
			//cout<<"carry2 "<<carry<<endl;
		}
		
		else{
			carry=0;
			//cout<<"carry3 "<<carry<<endl;
		}
		answer += column*danswer;
		column *= 10;
		digit1 = 0,digit2 = 0;
		//cout<<"digits "<<digit1<<digit2<<endl;
		//cout<<"danswer "<<danswer<<endl;
		//cout<<"carry "<<carry<<endl;

		cout<<"answer "<<answer<<endl;
		danswer = 0;
	

	}
	binary sum;
	sum.num = answer;
	return sum;*/
};

int main(){
	binary one,two;
	cin >>one;
	cin>>two;
	binary three = one+two;
	cout<<three<<endl;
	cout<<three+two<<endl;
}