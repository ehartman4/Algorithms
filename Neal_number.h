// File name:	NealA1.cpp
// Name:		Richard Neal
// Description:	This program can take binary numbers and add or convert them to decimal
// Input:		Accepts stdin or a string with the binary number to be inputted.
// Output:		Returns a string representation or stdout of the binary itself or its decimal form.

#ifndef NEAL_NUMBER_H
#define NEAL_NUMBER_H

#include <iostream>
#include <math.h>

using namespace std;


class binary {
	public:
		binary();
		binary(string);
		friend istream& operator>>(istream& in, binary& b);
		friend ostream& operator<<(ostream& out, binary& b);
		binary operator+ (binary);
		void operator+= (binary);
		long decimal();
	private:
		bool value [20];
};

#endif