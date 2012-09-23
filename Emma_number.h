#include <iostream>

using namespace std;

class binary{
	int num;
	binary decimal();
public:
	binary operator+ (int);
	binary& operator+= (int);
	friend ostream& operator<< (ostream&, binary);
	friend istream& operator>> (istream&, binary&);

};

binary binary::operator+ (binary twonum)
{
	int add1 = num;
	int add2 = twonum.num;
	int digit1,digit2,danswer,answer,carry=0,0,0,0,0;
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
	while (add1>0) and (add2>0){
		if (add1%2==1){
			digit1 = 1;
			add1 -= 1;
		}
		add1 /= 10;
		if (add2%2==1){
			digit2 = 1;
			add1 -= 1;
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
		else{
			carry=0;
		}
		answer += (10^loop)*danswer;
		loop +=1;
		digit1,digit2 = 0,0;
		cout<<add1<<add2<<endl;
	}
	binary sum;
	sum.num = answer;
	return sum;
};

void main(){
	binary one,two;
	one.num = 101;
	two.num = 11;
	binary three = one+two;
	cout<<three<<endl;
}