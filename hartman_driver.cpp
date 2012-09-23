/*
File name:		hartman_driver.cpp
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
int main(){
	cout<<"Enter two binary numbers: ";
	binary one,two;
	cin>>one; //demonstrating instream overloading
	cin>>two;

	cout<<"The decimal equivalent of the first number, "<<one<<", is: "<<one.decimal()<<endl;// demonstrating decimal method
	binary three = one+two; //demonstrating = overloading and + overloading
	
	cout<<"The sum of the two numbers is: "<<three<<endl; //demonstrating out stream overloading of binary class instance

	three +=two; //demonstrating += overloading
	cout<<"Add "<<two<<" to this number and you get: "<<three<<endl;
	one = one + two; //more demonstration of = and + overloaders for binary class
	cout<<"New first number: "<<one<<endl;
	cout<<two<<" base 2 equals "<<two.decimal()<<" base 10"<<endl; //more demonstration of decimal method
	cout<<three<<" base 2 equals "<<three.decimal()<<" base 10"<<endl;
}