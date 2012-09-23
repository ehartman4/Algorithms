/*
File name:		hartman_number.cpp
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
#include "hartman_number.h"

//converts the binary number to a decimal, out puts that decimal as an int
int binary::decimal()
{
	int dec = 0;
	int column = 1;
	//loop through the bitset, multiplying each number by the corresponding
	//  power of 2 and adding it to the decimal number "dec"
	for (int bin = 0; bin < 20; ++bin){
		dec += column*bitnum[bin];
		column *= 2;
	}
	return dec;
}

//when a string is input from the istream, this method is called to create
//  a bitset corresponding to the input string that will then be used throughout the program.
//  the function returns a bitset which will then be set as the bitset "bitnum" in the binary
//  class instance being tampered with.
bitset<20> binary::chop()
{
	bitset<20> inbit;
	// bitsets are stored in revers order, so this takes the last digit in the input string,
	//   which is index [0] in the bitset, and sets it as sch, and so on.
	for (int i = 0; i < strnum.length(); ++i)
	{
		if (strnum[strnum.length()-1-i]=='1'){
			inbit.set(i);
		}
	}
	return inbit;
}

//overloads the ostream operator << so that it will print out the bitset, but without all the
//  extraneous 0's since I'm storing every binary number as a bitset of size 20, regardless
//  of it's actual size.
ostream& operator<< (ostream& co, binary b)
{
	int it = 0;
	int pos = 19;
	// decides whwere to start actually printing out the bitset-style number.
	// For example, 101 is stored as 17 0's and then 101, so it would print out as such. This
	//   finds the first '1' in the number (the largest power of 2 for which there is a '1'),
	//   and starts displaying with this value.
	while (it==0 and pos>0){
		if (b.bitnum[pos]==1){
			it=1;
		}
		else{pos -= 1;}
	}
	for (int i = pos; i >=0; --i)
	{
		co<<b.bitnum[i];
	}
	return co;
}

//overloads the istream operator << for an instance of the binary class by taking in the
//  input as a string, calling the chop() method to create the corresponding bitset, and
//  returning the instream.
istream& operator>> (istream& ci, binary& b)
{
	ci >> b.strnum;
	b.bitnum = b.chop();
	return ci;
}

//overloads the = operator for binary instances. Sets the bitnum on the left equal to the
//  bitnum on the right -- this is the only piece of info that really needs to be transferred.
binary binary::operator= (binary right)
{
	bitnum = right.bitnum;
	return *this;
}

//overloads += operator. This and the + overload method are very similar but += resets the
//  bitnum value of the left operand to the summed binary number.
binary& binary::operator+= (binary right)
{
	int digit1=0,digit2=0,danswer=0,carry=0;
	bitset <20>answer;
	for (int i = 0; i < 20; ++i){
		if (bitnum[i]==1){
			digit1 = 1;
		}
		if (right.bitnum[i]==1){
			digit2 = 1;
		}
		//determines the number for this "column" of the binary number beofre carrying happens.
		danswer = digit1+digit2+carry;
		// now carrying is decided - the "carry" int is not reset at the end of this iteration
		//   of the loop, becase it factors into the next digit in the number.
		if (danswer==2){
			danswer=0;
			carry=1;
		}
		else if (danswer==3){
			danswer=1;
			carry=1;
		}
		else{carry=0;}
		// sets the sum digit in the correct column to whatever it should be.
		answer[i] = danswer;
		//rests the values used for the adding, but NOT the carry (this is needed for the next column)
		digit1 = 0,digit2 = 0,danswer = 0;
	}
	bitnum = answer;
	
}

//overloads + operator. This and the += overload method are very similar but + returns the
//  bitnum value produced.
binary binary::operator+ (binary twonum)
{
	int digit1=0,digit2=0,danswer=0,carry=0;
	bitset <20>answer;
	// (comments would be the same as above, in the += overloader)
	for (int i = 0; i < 20; ++i){
		if (bitnum[i]==1){
			digit1 = 1;
		}
		if (twonum.bitnum[i]==1){
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
		answer[i] = danswer;
		digit1 = 0,digit2 = 0,danswer = 0;
	}
	binary sum;
	sum.bitnum = answer;
	return sum;
};
