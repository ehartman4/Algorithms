#include <iostream>

using namespace std;

int gcf(int numerator, int denominator){
	int larger, smaller;
	if(denominator > numerator){
		larger = denominator;
		smaller = numerator;
	}
	else {
		larger = numerator;
		smaller = denominator;
	}
	int i = 2;
	int gcf = 1;
	while(i <= smaller)
	{
		if((smaller % i == 0) && (larger % i == 0)){
			smaller /= i;
			larger /= i;
			gcf *= i;
		}
		else{
			i++;
		}
	}
	return gcf;
}

int main() {
	cout<<gcf(2,1);

	
	float result;
	for (int i = 1; i < 21; ++i)
	{
		result = 0;
		for (int j = 1; j <= i; ++j)
		{
			result += gcf(i,j);
		}
		result /= i;
		cout<<"i: "<<i<<" Davg: "<<result<<endl;
	}
	
}