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
	int size;
	
	//string sort_type;
	double avg;
	double median;
	double largeval;
	double smallval;
	int ncols;
	int nrows;
	bool sortcheck;
public:
	GRD(){NODATA_check = 0;avg=0;sortcheck=0;};
	void getdata();
	double rmse(GRD);
	vector<double> BubbleSort(vector<double>);
	void sort(string);
	void mean();
	void larsmaval();
	void get_median();
	string file;

};

void GRD::getdata(){
	ifstream myfile;
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
	
	ncols = atoi(sncols.c_str());
	cout<<ncols<<endl;

	getline(myfile,line);
	pos = line.find(' ');
	string snrows = line.substr(pos+1);
	pos = snrows.find(' ');
	if (pos!=string::npos)
	{
		snrows.erase(pos,1);
	}
	nrows = atoi(snrows.c_str());
	cout<<nrows<<endl;
	getline(myfile,line);
	getline(myfile,line);
	getline(myfile,line);
	
	//while (myfile.good()){
	
	getline(myfile,line,' ');
	if (line=="NODATA_value"){
		getline(myfile,line,'\n');
		NODATA_value = atof(line.c_str());
		NODATA_check = 1;
		getline(myfile,line,' ');
	}
	
	for (int i = 0;i<nrows;i++){
		for (int j = 0; j < ncols; ++j)
		{
			if (j==0 and line[0]=='\n'){
				line.erase(0,1);
			}
			allval.push_back(atof(line.c_str()));
			if (NODATA_check==1){
				if (atof(line.c_str())!=NODATA_value){
					values.push_back(atof(line.c_str()));
				}
			}
			else{values.push_back(atof(line.c_str()));}
			cout<<i<<"  "<<j<<" "<<line<<endl;
			getline(myfile,line,' ');
		}
	}
	myfile.close();
	size = values.size();
}

double GRD::rmse (GRD other){
	double sum = 0;
	for (int i = 0; i < allval.size(); ++i)
	{
		if ((NODATA_check==1 and allval[i]==NODATA_value) or (other.NODATA_check==1 and other.allval[i]==other.NODATA_value)){
			sum = sum;
		}
		else{
			sum += (allval[i]-other.allval[i])*(allval[i]-other.allval[i]);
		}
		
	}
	sum /= allval.size();
	sum = sqrt(sum);
	return sum;
}

void GRD::mean (){
	for (int i = 0; i < values.size(); ++i)
	{
		avg += values[i];
	}
	avg /= values.size();
}

void GRD::get_median (){
	if (sorted.size()%2==0)
	{
		median = (sorted[sorted.size()/2]+sorted[(sorted.size()/2)-1])/2;
	}
	else {median = sorted[sorted.size()/2];}
}

void GRD::larsmaval(){
	largeval = sorted[sorted.size()-1];
	smallval = sorted[0];
}

void GRD::sort(string sort_type){
	sortcheck = 1;
	if (sort_type=="bubble"){
		sorted = BubbleSort(values);
	}
	else if (sort_type=="STL"){
		vector<double> temp;
		temp=values;
		//////////figure out STL sort!!!
		//values.sort();
		sorted = values;
		values = temp;
	}
}


vector<double> GRD::BubbleSort (vector<double> val)
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
	GRD first;
	GRD second;
	string type;
	cout<<"First filename: ";
	//string file;
	//const char filepoop;
	cin>>first.file;
	//file = &filepoop;

	cout<<"Second filename: ";
	//string file;
	//const char filepoop;
	cin>>second.file;
	cout<<"Type of Sort: ";
	cin>>type;
	first.getdata();
	second.getdata();

	first.mean();
	second.mean();
	first.rmse(second);
	first.sort(type);
	second.sort(type);
	first.larsmaval();
	second.larsmaval();

	first.get_median();
	second.get_median();
	
	return 0;
}