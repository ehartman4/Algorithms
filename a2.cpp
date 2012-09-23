#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


class number{
public:
	string strnum;
	int base;
	vector<int> bitnum;
	number () {vector<int> thebitnum (20,0);};//empty constructor for binary
	number (int thebase, vector<int> thebitnum) {base = thebase; bitnum = thebitnum;};
	vector<int> chop();
	int decimal();
	friend istream& operator>> (istream&, number&);
	friend ostream& operator<< (ostream&, number);
	number operator+ (number);	
};

vector<int> number::chop()
{
	vector<int> innum (20,0);
	// bitsets are stored in revers order, so this takes the last digit in the input string,
	//   which is index [0] in the bitset, and sets it as sch, and so on.
	vector<int>::iterator it;
	it = innum.begin();
	for (int i = 0; i < strnum.length(); ++i)
	{
		innum.pop_back();
		if (base==16){
			if (strnum[i] == 'A' or strnum[i] == 'a'){
				innum.insert(it,10);}
			else if (strnum[i] == 'B' or strnum[i] == 'b'){
				innum.insert(it,11);}
			else if (strnum[i] == 'C' or strnum[i] == 'c'){
				innum.insert(it,12);}
			else if (strnum[i] == 'D' or strnum[i] == 'd'){
				innum.insert(it,13);}
			else if (strnum[i] == 'E' or strnum[i] == 'e'){
				innum.insert(it,14);}
			else if (strnum[i] == 'F' or strnum[i] == 'f'){
				innum.insert(it,15);}
			else{innum.insert(it,atoi(strnum.substr(i,1).c_str()));}
			}
		else{
			innum.insert(it,atoi(strnum.substr(i,1).c_str()));}
	}
	return innum;
}

int number::decimal(){
	int dec = 0;
	int column = 1;
	//loop through the bitset, multiplying each number by the corresponding
	//  power of 2 and adding it to the decimal number "dec"
	for (int bin = 0; bin < 20; ++bin){
		dec += column*bitnum[bin];
		column *= base;
	}
	return dec;
}

istream& operator>> (istream& ci, number& b)
{
	ci >> b.strnum;
	b.bitnum = b.chop();
	return ci;
}

ostream& operator<< (ostream& co, number b)
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
		if (b.base==16){
			if (b.bitnum[i] == 10){
				co<<'A';}
			else if (b.bitnum[i] == 11){
				co<<'B';}
			else if (b.bitnum[i] == 12){
				co<<'C';}
			else if (b.bitnum[i] == 13){
				co<<'D';}
			else if (b.bitnum[i] == 14){
				co<<'E';}
			else if (b.bitnum[i] == 15){
				co<<'F';}
			else{co<<b.bitnum[i];}
			}
		else{
			co<<b.bitnum[i];}
	}
	return co;
}

number number::operator+ (number right)
{
	int digit1=0,digit2=0,danswer=0,carry=0;
	vector <int> answer (20,0);
	for (int i = 0; i < 20; ++i){
		digit1 = bitnum[i];
		digit2 = right.bitnum[i];
		//determines the number for this "column" of the binary number beofre carrying happens.
		danswer = digit1+digit2+carry;
		// now carrying is decided - the "carry" int is not reset at the end of this iteration
		//   of the loop, becase it factors into the next digit in the number.

		carry = danswer/base;
		danswer = danswer%base;
		
		// sets the sum digit in the correct column to whatever it should be.
		answer[i] = danswer;
		//rests the values used for the adding, but NOT the carry (this is needed for the next column)
		digit1 = 0,digit2 = 0,danswer = 0;
	}
	number sum(base,answer);
	sum.bitnum = answer;
	return sum;
}

class binary : public number {
public:
	binary(){base = 2;};
	binary(vector<int> thebitnum) {base = 2; bitnum = thebitnum;};
	binary operator+(binary);
};

binary binary::operator+ (binary right){
	number numsum = number::operator+(right);
	binary sum (numsum.bitnum);
	return sum;
}

class octal : public number {
public:
	octal(){base = 8;};
	octal(vector<int> thebitnum) {base = 8; bitnum = thebitnum;};
	octal operator+(octal);

};

octal octal::operator+ (octal right){
	number numsum = number::operator+(right);
	octal sum (numsum.bitnum);
	return sum;
}

class hexadecimal : public number {
public:
	hexadecimal(){base = 16;};
	hexadecimal(vector<int> thebitnum) {base = 16; bitnum = thebitnum;};
	hexadecimal operator+(hexadecimal);
};

hexadecimal hexadecimal::operator+ (hexadecimal right){
	number numsum = number::operator+(right);
	hexadecimal sum (numsum.bitnum);
	return sum;
}


int main(){
	/*
	vector<int> neb (20,0);
	//number three (16,neb);
	//number four (16,neb);
	hexadecimal three;
	hexadecimal four;
	cin>>three;
	cin>>four;
	cout<<three<<endl;
	cout<<three+four<<endl;
	hexadecimal five = three+four;
	//hexadecimal six = five;
	cout<<five<<endl;
	//cout<<"six"<<six<<endl;
	cout<<three.decimal()<<endl;
	return 0;
	*/

	binary bnum, bnum2, bnum3;
	hexadecimal hnum;
	octal onum1, onum2;
	cout << "Enter binary: ";
	cin >> bnum;
	cout << "Enter binary2: ";
	cin >> bnum2;
	bnum3 = bnum + bnum2;
	cout << "Sum: " << bnum3 << endl;
	cout << "Enter hex: ";
	cin >> hnum;
	cout << "Hex number is: " << hnum << endl;
	cout << "Its decimal value is: " << hnum.decimal () << endl;
	cout << "Enter octal: ";
	cin >> onum1;
	cout << "Octal number is: " << onum1 << endl;
	cout << "Its decimal value is: " << onum1.decimal () << endl;
	onum2 = onum1;
	cout << "The decimal value of onum2 is: " << onum2.decimal () << endl;
	return 0;
}