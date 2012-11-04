#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class Files{
public:
	Files(){};
	string fname;
	int N;
	int write();
	void read(string);
	vector<int> values;
	int medsort();
	int median;
};
int Files::write(){

	cout<<"N (odd): ";
	cin>>N;
	ofstream myfile;
	myfile.open ("N999999.txt");
	myfile<<N<<"\n";
	for (int i = 0; i < N; ++i)
	{
		myfile<<rand() % 999 + 1<<"\n";
	}
	myfile.close();
	return 0;
}

void Files::read(string fnamein){
	fname = fnamein;
	ifstream infile;
	infile.open (fname.c_str());
	string line;
	getline(infile, line);
	N = atoi(line.c_str());
	//cout<<N<<endl;
	
	for (int i = 0; i < N; ++i)
	{
		getline(infile, line);
		values.push_back(atoi(line.c_str()));
	}
	/*
	for (int i = 0; i < N; ++i)
	{
		cout<<values[i]<<endl;
	}
	*/
}

int Files::medsort(){
	sort(values.begin(),values.end());
	/*
	for (int i = 0; i < values.size(); ++i)
	{
		cout<<values[i]<<endl;
	}
	*/
	median = values[N/2];
	
	return 0;
}

int main(){
	double start,stop;
	Files n99;
	string fname;
	cout<<"Filename: ";
	cin>>fname;
	start = (double) clock ();
	n99.read(fname);
	n99.medsort();
	stop = (double) clock ();
	cout<<"N: "<<n99.N<<endl;
	cout<<"Median:"<<n99.median<<endl;
	cout<<"Time:"<<stop-start<<endl;
	return 0;
}