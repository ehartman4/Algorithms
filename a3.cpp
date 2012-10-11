#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

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
	ifstream myfile;
	cout<<"Filename: ";
	string file;
	//const char filepoop;
	cin>>file;
	//file = &filepoop;
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

	if (NODATA_check==0)
	{
		for (int i = 0;i<nrows;i++){
			for (int j = 0; j < ncols; ++j)
			{
				if (j==0 and line[0]=='\n'){
					line.erase(0,1);
				}

				if (atof(line.c_str())!=NODATA_value){
					values.push_back(atof(line.c_str()));
					avg += atof(line.c_str());
				}
				cout<<i<<"  "<<j<<" "<<line<<endl;
				getline(myfile,line,' ');
			}
			//getline(myfile,line);
			//cout<<i<<" "<<line<<endl;
		}
	}
	
	else{
		for (int i = 0;i<nrows;i++){
			for (int j = 0; j < ncols; ++j)
			{
				if (j==0 and line[0]=='\n'){
					line.erase(0,1);
				}

				if (atof(line.c_str())!=NODATA_value){
					values.push_back(atof(line.c_str()));
					avg += atof(line.c_str());
				}
				cout<<i<<"  "<<j<<" "<<line<<endl;
				getline(myfile,line,' ');
			}
			//getline(myfile,line);
			//cout<<i<<" "<<line<<endl;
		}
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