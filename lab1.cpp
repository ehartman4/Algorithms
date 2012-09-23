#include <iostream>

using namespace std;

class fraction {
public:
	friend ostream& operator<<(ostream& out, const fraction& f);
	friend istream& operator>>(istream& in, fraction& f);
	int numerator;
	int denominator;
	fraction gcf(int,int);
	fraction(){};
	fraction(int,int);
	fraction operator+ (fraction);
};

class mixed : public fraction{
protected:
	int integer;
	friend ostream& operator<<(ostream& out, const mixed& m);
	mixed operator+ (mixed);
public:
	mixed(){};
	mixed(int,int);
	mixed operator= (fraction);
};

mixed::mixed(int num, int den){
	integer = num/den;
	numerator = num % den;
}

ostream& operator<<(ostream& output, const mixed& m) {
	output << m.integer << " " << m.numerator << '/' << m.denominator;
	return output;
}


mixed mixed::operator+(mixed two){
	int newint;
	fraction onefrac, twofrac, newfrac;
	newint = integer+ two.integer;
	onefrac = fraction(numerator,denominator);
	twofrac = fraction(two.numerator,two.denominator);
	newfrac = onefrac + twofrac;
	return mixed(newfrac.numerator + newint * newfrac.denominator, newfrac.denominator);
}

mixed mixed::operator=(fraction frac){
	mixed newMixed;
	newMixed.integer = frac.numerator/frac.denominator;
	newMixed.numerator = frac.numerator % frac.denominator;
	newMixed.denominator = frac.denominator;
	return newMixed;
}

fraction::fraction(int num, int den){
	numerator = num;
	denominator = den;
}


ostream& operator<<(ostream& output, const fraction& f) {
	output << f.numerator << '/' << f.denominator;
	return output;
}

istream& operator>>(istream& in, fraction& f){
	int numerator, denominator;
	in >> numerator;
	in.get();
	in >> denominator;
	f = f.gcf(numerator, denominator);

	return in;
}

fraction fraction::operator+ (fraction two) {
	int sum_num, sum_den, smallden, largeden, remainder;
	if(denominator > two.denominator){
		largeden = denominator;
		smallden = two.denominator;
	}
	else {
		largeden = two.denominator;
		smallden = denominator;
	}
	if(largeden % smallden == 0){
		sum_den = largeden;
	}
	else {
		remainder = largeden % smallden;
		while(remainder != 0){
			largeden = smallden;
			smallden = remainder;
			remainder = largeden % smallden;
		}
		sum_den = (denominator * two.denominator) / smallden;
	}
	sum_num = numerator * (sum_den / denominator) + two.numerator * (sum_den / two.denominator);

	return fraction(fraction::gcf(sum_num, sum_den));
}

fraction fraction::gcf(int numerator, int denominator){
	int larger, smaller;
	bool numsmall;
	if(denominator > numerator){
		larger = denominator;
		smaller = numerator;
		numsmall = true;
	}
	else {
		larger = numerator;
		smaller = denominator;
		numsmall = false;
	}
	int i = 2;
	while(i <= smaller)
	{
		if((smaller % i == 0) && (larger % i == 0)){
			smaller /= i;
			larger /= i;
		}
		else{
			i++;
		}
	}
	if (numsmall == true)
	{
		numerator = smaller;
		denominator = larger;
	}
	else {
		numerator = larger;
		denominator = smaller;
	}
	return fraction(numerator, denominator);
}

int main() {
	fraction one, two, three;
	cin >> one;
	cin >> two;
	cout << one << "  " << two << endl;
	three = one + two;
	cout << three << endl;

	mixed four, five;
	four = one + two;
	//cin >> four;
	cout << four << endl;
}