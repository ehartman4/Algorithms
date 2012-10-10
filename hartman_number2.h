/*
File name:		hartman_number2.h
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

//The structure for the octal and hexadecimal classes are identical to that of binary.
class octal : public number {
public:
	octal(){base = 8;};
	octal(vector<int> thebitnum) {base = 8; bitnum = thebitnum;};
	octal operator+(octal);

};


class hexadecimal : public number {
public:
	hexadecimal(){base = 16;};
	hexadecimal(vector<int> thebitnum) {base = 16; bitnum = thebitnum;};
	hexadecimal operator+(hexadecimal);
};
