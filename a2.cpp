/*
File name:		hartman_driver.cpp
Date:			September 23, 2012
Name:			Emma Hartman
Description:	Adds and displays binary, octal, and hexadecimal numbers of up to 20 digits
				(homogeneously) and converts them to decimals.
Input:			Two hexadecimal numbers, then two octal numbers, then two binary number. Hex
				numbers use the digits 0-F. For the letters, representing decimal numbers 11-15,
				upper or lower case will be accepted.  Input numbers can be from 1 to 20 digits
				each. (To use 0 you must type 0, you cannot simply leave the field blank.)
Output: 		Depends on your driver function. Mine outputs:
					- The first hex number entered and its decimal equivalent
					- The second hex number entered and its decimal equivalent
					- The sum of the two numbers entered so far and its decimal equivalent
					- The first octal number and its decimal equivalent
					- The sum of the first and second octal numbers
					- The sum of the first and second binary numbers
					- The decimal equivalent of the first binary number + the second binary,
					  which has now replaced the value of the first binary number
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


class number{
protected:
	string strnum;
	int base;
	vector<int> bitnum;
	vector<int> chop();
public:
	number () {vector<int> thebitnum (20,0);}; //empty constructor for any number, sets the size/value of bitnum to 20 0's, since the initial setting of the number is supposed to be 0.
	number (int thebase, vector<int> thebitnum) {base = thebase; bitnum = thebitnum;}; //copy constructor - takes in a base (2,8,or 16) and a bitnum int vector.
	int decimal();
	vector<int> get_bitnum();
	friend istream& operator>> (istream&, number&);
	friend ostream& operator<< (ostream&, number);
	number operator+ (number);	
};

//pre-condition:  the instance has a strnum value of between 1 and 20 characters in length. 
//post-condition: a vector of ints "innum" has been created, storing the values of strnum
//                as individual ints for each "column" of the input strnum number.
vector<int> number::chop()
{
	vector<int> innum (20,0);
	// I stored my numbers in reverse order, so the first number in the vector's is the
	//   base^0 column, the second is the base^1 column, etc. I acheived this by inserting
	//   the digits, starting with the first sequentially entered by the user, into the
	//   first slot of the vector every time. Each time an int was inserted into the front
	//   of the vector, I erased a 0 off the end of the vector so that the vecto would
	//   remain 20 ints in length.
	vector<int>::iterator it;
	it = innum.begin();
	for (int i = 0; i < strnum.length(); ++i)
	{
		innum.pop_back();
		if (base==16){
			//In the case of hexadecimal numbers, we want to do arithmetic on the digits
			//   in terms of decimal digits, so I converted the digits A-F to decimal 10-15.
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


//pre-condition:  The instance has a vector of ints bitnum that is 20 ints long. 
//post-condition: An int that represents the decimal equivalent of the input number
//                in the assigned base.
int number::decimal(){
	int dec = 0;
	int column = 1;
	//loop through the vector, multiplying each number by the corresponding power of the
	//   base of the number and adding it to the decimal number "dec".
	for (int bin = 0; bin < 20; ++bin){
		dec += column*bitnum[bin];
		column *= base;
	}
	return dec;
}
// This is a public method of number created to access the private data value of bitnum,
//    which is necessary for certain aspects of the inheritance in this program.
vector<int> number::get_bitnum(){
	return bitnum;
}

//pre-condition:	A string, no more than 20 characters in length, of legal input. For
//					binary, this means each character must be '0' or '1'. For octal, this
//					means each character must be '0','1','2','3','4','5','6', or '7'. For
//					hexadecimal, this means each character must be '0','1','2','3','4','5',
//					'6','7','8','9','A','B','C','D','E','F','a','b','c','d','e', or 'f'.
//					(Hex numbers will be accepted in either lower or upper case.)
//post-condition:	The instream is returned.
istream& operator>> (istream& ci, number& b)
{
	ci >> b.strnum;
	// The instream is fed into a string, "strnum", which then is used in the chop()
	//    function create a bitnum vector of ints to represent that string appropriately.
	b.bitnum = b.chop();
	return ci;
}

//pre-condition:	A number object b that has a valid bitnum string and base value.
//post-condition:	Printed out a correct visual representation of the number that is stored
//					in the bitnum corresponding to this number object.
ostream& operator<< (ostream& co, number b)
{
	bool it = 0;
	int pos = 19;
	// Decides where to start actually printing out the int vector number. For example, for
	//   an octal number, 783 is stored as 3,8,7, and then 17 0's, so it would print out as
	//   such. This finds the first non-zero in the number going backwards from the end of
	//   the vector, which wuld be the largest "column" in the number, and starts displaying
	//   with this largest non-zero value.
	while (it==0 and pos>0){
		if (b.bitnum[pos]==0){
			pos -=1;
		}
		else{it=1;}
	}
	// For the case of hexadecimal, just like in the "chop" function, we need to account
	//    for how the digits A-F are displayed vs. how they're stored. This series of if
	//    statements makes it so that the correct letter is displayed for the corresponding
	//    digit value in decimal.
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

//pre-condition:	The input "right" must be a valid instance of the number class - this
//					means an instance of the number class OR ANY of its child classes. So
//					input could be a binary, octal, or hexadecimal number as well. It must
//					match the object tyoe of the number it is being added to though, so the
//					valid options are: number + number, binary + binary, octal + octal, or
//					hexadecimal  + hexadecimal.
//post-condition:	A number object is returned, which has the same base as the two input
//					numbers and the bitnum vector of this new number represents the sum of
//					the two input numbers in their own base. Note, however, that this
//					output's data type will ALWAYS be number - it will not return a binary,
//					octal, or hexadecimal instance.
number number::operator+ (number right)
{
	int digit1=0,digit2=0,danswer=0,carry=0;
	vector <int> answer (20,0);
	for (int i = 0; i < 20; ++i){
		digit1 = bitnum[i];
		digit2 = right.bitnum[i];
		//determines the number for this "column" of the summed number before carrying for
		//   the next column happens.
		danswer = digit1+digit2+carry;

		// now carrying is decided - the "carry" int is not reset at the end of this iteration
		//   of the loop, becase it factors into the next digit in the number.
		carry = danswer/base;
		danswer = danswer%base;
		
		// sets the sum digit in the correct column to whatever it should be.
		answer[i] = danswer;
		//resets the values used for the adding, but NOT the carry (this is needed for
		//   calculating the next column's digit)
		digit1 = 0,digit2 = 0,danswer = 0;
	}
	//sets the base of the output number to the same base as those of the input numbers and
	//   the bitnum of the output number to the bitnum created here - the representation of
	//   the sum of the numbers.
	number sum(base,answer);
	return sum;
}

//Binary inherits from number using "public", so the data types remain public and protected
//   in number, just as they are in number itself.
class binary : public number {
public:
	binary(){base = 2;}; //This constructor automatically calls the number constructor and
	//						also sets the base to 2.
	binary(vector<int> thebitnum) {base = 2; bitnum = thebitnum;}; //This copy constructor
	//	allows creation of a binary number from the necessary information - the int vector
	//	representing the number.
	binary operator+(binary);
};


//pre-condition:	Input a valid binary number as the right operand.
//post-condition:	Returns the sum of the two numbers in the form of a new binary number
//					called "sum", containing the bitnum of the sum of the two numbers input.
binary binary::operator+ (binary right){
	number numsum = number::operator+(right);
	// Since number:operator+ already exists and we don't want to repeat that code, we can
	//    call it again. It will output a number object, however, so we then need to use the
	//    bitnum of that number object in creating an instance of binary which is equivalent.
	binary sum (numsum.get_bitnum());
	return sum;
}

//The structure for the octal and hexadecimal classes are identical to that of binary.
class octal : public number {
public:
	octal(){base = 8;};
	octal(vector<int> thebitnum) {base = 8; bitnum = thebitnum;};
	octal operator+(octal);

};

octal octal::operator+ (octal right){
	number numsum = number::operator+(right);
	octal sum (numsum.get_bitnum());
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
	hexadecimal sum (numsum.get_bitnum());
	return sum;
}


int main(){
	
	
	binary bnum, bnum2, bnum3;
	hexadecimal hnum,hnum2,hnum3;
	octal onum1, onum2;
	//showing hex instream overloading
	cout << "Enter a hexadecimal number: ";
	cin >> hnum;
	cout << "Enter another hex number: ";
	cin >> hnum2;
	//demonstrating hex conversion to binary and printing hex
	cout << "The first number, "<<hnum<<", converted to decimal is: "<<hnum.decimal()<<endl;
	cout << "The second number, "<<hnum2<<", converted to decimal is: "<<hnum2.decimal()<<endl;
	//demonstrating hex addition and = overloading
	hnum3 = hnum+hnum2;
	cout<< "In hex, their sum is: "<<hnum3<<". In decimal, that's: "<<hnum3.decimal()<<endl;
	//showing octal instream, outstream, and + overloading, and deciaml conversion.
	cout << "Enter an octal number: ";
	cin >> onum1;
	cout << "Octal number is: " << onum1 << endl;
	cout << "Its decimal value is: " << onum1.decimal () << endl;
	cout << "Enter another octal: ";
	cin >> onum2;
	cout << "The sum of these two octal numbers is: " << onum1+onum2 << endl;
	//demonstrating instream, outstream, +, and = overloading of binary, as well as decimal
	//   conversion.
	cout << "Enter a binary number: ";
	cin >> bnum;
	cout << "...and another: ";
	cin >> bnum2;
	bnum3 = bnum+bnum2;
	cout << "Their sum is: " << bnum3 << endl;
	bnum = bnum3;
	cout << "The decimal value of bnum is now: "<< bnum.decimal() << endl;
	return 0;
}