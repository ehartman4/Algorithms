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
#include "hartman_number2.h"

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
	cout << "The sum of these two octal numbers in octal is: " << onum1+onum2 << endl;
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