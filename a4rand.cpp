#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){

	FILE * pFile;
	pFile = fopen ("myfile2.txt","w");
	int n = 10; //number of data points
	fprintf (pFile, "%i\n", n);
	for (int i = 0; i < n; ++i)
	{
		fprintf (pFile, "%i %i\n", rand() % 100 + 1, rand() % 100 + 1);
		//coordinate values can range from 0 to 100 - this is completely arbitrary
	}
	
	return 0;
}