/*
File name:		hartman_number.h
Date:			September 13, 2012
Name:			Emma Hartman
Description:	Adds and displays binary numbers and converts them to decimals.
Input:			Two binary numbers, so any two strings of 0's and 1's, from 1 to 20
				digits each. (To use 0 you must type 0, you cannot simply leave the
				field blank)
Output: 		Depends on your driver function. Mine outputs:
					- The decimal equivalent of the first number entered
					- The sum of the two numbers entered
					- The sum of those two numbers and the second number again
					- The sum of the two numbers entered again, which is the new
					  value of the first number
					- The decimal equivalent of the second number entered
					- The decimal equivalent of the first number + the second number twice
}
*/

#ifndef HARTMAN_NUMBER_H
#define HARTMAN_NUMBER_H


#include <bitset>
#include <iostream>

using namespace std;

class binary{
	bitset<20> bitnum;
	string strnum;
public:
	binary () {};//empty constructor for binary
	binary (bitset<20> thebitnum, string thestrnum) {bitnum = thebitnum; strnum = thestrnum;}; // copy constructor for binary
	bitset<20> chop();
	int decimal();
	binary operator= (binary);
	binary operator+ (binary);
	binary& operator+= (binary);
	friend ostream& operator<< (ostream&, binary);
	friend istream& operator>> (istream&, binary&);
};

#endif