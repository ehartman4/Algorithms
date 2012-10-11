#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

class GRD{
protected:
	vector<double> values;
	vector<double> allval;
	vector<double> sorted;
	bool NODATA_check;
	double NODATA_value;
	string file;
	string sort_type;
	double avg;
	double largeval;
	double smallval;
public:
	GRD::GRD(){NODATA_check = 0;};
	void getdata();
	double rmse(GRD);
	void BubbleSort();
	void Sort();
	void avg();
	void larsmaval();

};

double rmse (vector<double> all1, vector<double> all2){
	double sum = 0;
	for (int i = 0; i < all1.size(); ++i)
	{
		if ((NODATA_check.all1==1 and all1[i]==NODATA_value.all1) or (NODATA_check.all2==1 and all2[i]==NODATA_value.all1)){
			sum = sum;
		}
		else{
			sum += (all1[i]-all2[i])**2;
		}
		
	}
	sum /= all1.size();
	sum = sqrt(sum);
	return sum;
}


vector<double> BubbleSort (vector<double> val)
{
   int counter = 0;
   int i;
   int pass;   // number of current pass through array
   double temp;   // temporary for use in exchanges
   int sorted; // whether or not array is sorted

   pass = 1;

   do {
      sorted = 1;  // assume sorted until determined otherwise

      for (i = 0; i < val.size()-pass; ++i) {
         if (val[i] > val[i + 1]) {
            // exchange out-of-order pair
            temp = val[i];
            val[i] = val [i + 1];
            val [i + 1] = temp;
            sorted = 0;
            counter++;
         }
      }
      ++pass;
   } while (! sorted);
   return val;
}

int main(){
	GRD first();
	GRD second();
	ifstream myfile;
	cout<<"First filename: ";
	//string file;
	//const char filepoop;
	cin>>first.file;
	//file = &filepoop;

	cout<<"Second filename: ";
	//string file;
	//const char filepoop;
	cin>>second.file;
	string line;
	size_t pos;
	myfile.open(file.c_str());
	getline(myfile,line);
	pos = line.find(' ');
	string sncols = line.substr(pos+1);
	pos = sncols.find(' ');
	if (pos!=string::npos)
	{
		sncols.erase(pos,1);
	}
	
	int ncols = atoi(sncols.c_str());
	cout<<ncols<<endl;

	getline(myfile,line);
	pos = line.find(' ');
	string snrows = line.substr(pos+1);
	pos = snrows.find(' ');
	if (pos!=string::npos)
	{
		snrows.erase(pos,1);
	}
	int nrows = atoi(snrows.c_str());
	cout<<nrows<<endl;
	getline(myfile,line);
	getline(myfile,line);
	getline(myfile,line);
	//QUESTION FOR TOMORROW: what can you use instead of null for int?
	/*getline(myfile,line,' ');
	if (line=="NODATA_value")
	{
		getline(myfile,line,' ');
		int NODATA_value = atoi(line.c_str());
	}
	else{int NODATA_value = NULL;}*/
	//while (myfile.good()){
	bool NODATA_check = 0;
	double NODATA_value;
	double avg = 0;
	vector<double> values;
	vector<double> allval;


	getline(myfile,line,' ');
	if (line=="NODATA_value"){
		getline(myfile,line,'\n');
		NODATA_value = atof(line.c_str());
		NODATA_check = 1;
		getline(myfile,line,' ');
	}
/*
	if (NODATA_check==0)
	{
		for (int i = 0;i<nrows;i++){
			for (int j = 0; j < ncols; ++j)
			{
				if (j==0 and line[0]=='\n'){
					line.erase(0,1);
				}	
				values.push_back(atof(line.c_str()));
				avg += atof(line.c_str());
				cout<<i<<"  "<<j<<" "<<line<<endl;
				getline(myfile,line,' ');
			}
			//getline(myfile,line);
			//cout<<i<<" "<<line<<endl;
		}
		allval = values;
	}
	*/
	
	for (int i = 0;i<nrows;i++){
		for (int j = 0; j < ncols; ++j)
		{
			if (j==0 and line[0]=='\n'){
				line.erase(0,1);
			}
			allval.push_back(atof(line.c_str()));
			if NODATA_check==1{
				if (atof(line.c_str())!=NODATA_value){
					values.push_back(atof(line.c_str()));
					avg += atof(line.c_str());
				}
			}
			else{
				values.push_back(atof(line.c_str()));
			}
			cout<<i<<"  "<<j<<" "<<line<<endl;
			getline(myfile,line,' ');
		}
		//getline(myfile,line);
		//cout<<i<<" "<<line<<endl;
	}


	myfile.close();

	for (int i = 0; i < values.size(); ++i)
	{
		cout<<values[i]<<endl;
	}

	cout<<"Values: "<<values.size()<<endl;
	values = BubbleSort(values);
	for (int i = 0; i < values.size(); ++i)
	{
		cout<<values[i]<<endl;
	}
	double median;
	if (values.size()%2==0)
	{
		median = (values[values.size()/2]+values[(values.size()/2)-1])/2;
	}
	else {median = values[values.size()/2];}
	avg /= values.size();
	cout<<"Mean: "<<avg<<endl;
	cout<<"Median: "<<median<<endl;
	cout<<"Largest Value: "<<values[values.size()-1]<<endl;
	cout<<"Smallest Value: "<<values[0]<<endl;

	return 0;
}