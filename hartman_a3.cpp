/*
File name:		hartmana3.cpp
Date:			October 11, 2012
Name:			Emma Hartman
Description:	Sorts two grd files and calculates mean, median, and RSEM.
Input:			two grd files and a choice of sort function.
Output: 		The Median, Mean, largest value, smallest value, RSEM of the files. Also out puts the algorithm analysis for the sort functions chosen and the overall progrm run time.
*/



#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>

using namespace std;

class GRD{
protected:
	vector<double> values;
	vector<double> allval;
	vector<double> sorted;
	bool NODATA_check;
	double NODATA_value;
	int size;
	double avg;
	double median;
	double largeval;
	double smallval;
	int ncols;
	int nrows;
	bool sortcheck;
public:
	GRD(){NODATA_check = 0;avg=0;sortcheck=0;counter=0;};
	double counter;
	double duration;
	void getdata();
	double rmse(GRD);
	vector<double> BubbleSort(vector<double>);
	void sortit(string);
	void mean();
	void larsmaval();
	void find_median();
	string file;
	int get_size(){return size;};
	double get_mean(){return avg;};
	double get_median(){return median;};
	double get_largeval(){return largeval;};
	double get_smallval(){return smallval;};
};

/*
Description: Collects the data from the given file, storing it for future use.
Pre-Condition: A properly formatted ESRI .grd file is given.
Post-Condition: Two vectors of doubles - one with the NODAT_value points included, one without.
*/
void GRD::getdata(){
	ifstream myfile;
	string line;
	size_t pos;
	myfile.open(file.c_str());
	getline(myfile,line);
	pos = line.find(' ');
	string sncols = line.substr(pos+1);
	pos = sncols.find(' ');
	if (pos!=string::npos){
		sncols.erase(pos,1);
	}
	ncols = atoi(sncols.c_str());
	getline(myfile,line);
	pos = line.find(' ');
	string snrows = line.substr(pos+1);
	pos = snrows.find(' ');
	if (pos!=string::npos){
		snrows.erase(pos,1);
	}
	nrows = atoi(snrows.c_str());
	getline(myfile,line);
	getline(myfile,line);
	getline(myfile,line);
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
			//cout<<i<<"  "<<j<<" "<<line<<endl;
			getline(myfile,line,' ');
		}
	}
	myfile.close();
	size = values.size();
}


/*
Description: Calculates the RMSE.
Pre-Condition: two instances of the GRD class, presumably of the same size (number of elements)
Post-Condition: result of the RMSE for the two files is calculating, skipping NODATA_value points.
*/
double GRD::rmse (GRD other){
	double sum = 0;
	for (int i = 0; i < allval.size(); ++i){
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

/*
Description: Calculates the mean of the elevation points.
Pre-Condition: A vector without NODATA_values is given
Post-Condition: Outputs the average (mean) of the values.
*/
void GRD::mean (){
	for (int i = 0; i < values.size(); ++i){
		avg += values[i];
	}
	avg /= values.size();
}

/*
Description: Calculates the median.
Pre-Condition:  A vector without NODATA_values is given, sorted.
Post-Condition: Outputs the median of the values.
*/
void GRD::find_median (){
	if (sorted.size()%2==0){
		median = (sorted[sorted.size()/2]+sorted[(sorted.size()/2)-1])/2;
	}
	else {median = sorted[sorted.size()/2];}
}


/*
Description: Finds the largest and smallest values in the .grd file.
Pre-Condition:  A vector without NODATA_values is given, sorted.
Post-Condition: Outputs the largest and smallest values of the list.
*/
void GRD::larsmaval(){
	largeval = sorted[sorted.size()-1];
	smallval = sorted[0];
}

/*
Description: Sorts the vector.
Pre-Condition:  A vector without NODATA_values is given, and a sort type, either "bubble" or "STL" is given.
Post-Condition: Outputs the sorted list, sorted by the chosen method.
*/
void GRD::sortit(string sort_type){

	double start, stop;
	sortcheck = 1;
	if (sort_type=="bubble"){
		start = (double) clock ();
		sorted = BubbleSort(values);
		stop = (double) clock ();
	}
	else if (sort_type=="STL"){
		start = (double) clock ();
		vector<double> temp;
		temp = values;
		sort(values.begin(),values.end());
		sorted = values;
		values = temp;
		stop = (double) clock ();
	}
	duration = stop-start;
}

/*
Description: Implements the bubble sort.
Pre-Condition:  A vector without NODATA_values is given unsorted.
Post-Condition: Outputs the vector, sorted, having counted iterations.
*/
vector<double> GRD::BubbleSort (vector<double> val)
{

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
	double startall, stopall, durationall;
	cout<<"First filename: ";
	cin>>first.file;
	if (first.file=="t"){
		first.file = "test.grd";
		second.file = "test2.grd";
		type = "STL";
	}
	else{
		cout<<"Second filename: ";
		cin>>second.file;
		cout<<"Type of Sort (enter either 'bubble' or 'STL'): ";
		cin>>type;
	}
	startall = (double) clock ();
	first.getdata();
	second.getdata();

	first.mean();
	second.mean();
	double error = first.rmse(second);
	first.sortit(type);
	second.sortit(type);
	first.larsmaval();
	second.larsmaval();

	first.find_median();
	second.find_median();

	int form = 11;
	stopall = (double) clock ();
	durationall = stopall-startall;
	printf("Time Overall: %.4f \n",durationall);
	printf("Time for sort of file 1: %.4f \n",first.duration);
	printf("Time for sort of file 2: %.4f \n",second.duration);

	if (type=="bubble")
	{
		cout<<"Number of Iterations for Bubble Sort of file 1: "<<first.counter<<endl;
		cout<<"Number of Iterations for Bubble Sort of file 2: "<<second.counter<<endl;
	}
	printf("%-21s| %-*s | %-*s \n","File name",form,"First File",form,"Second File");
	printf("%-21s| %*d | %*d \n","Number of data points",form,first.get_size(),form,second.get_size());
	printf("%-21s| %*.2f | %*.2f \n","Highest elevation",form,first.get_largeval(),form,second.get_largeval());
	printf("%-21s| %*.2f | %*.2f \n","Lowest elevation",form,first.get_smallval(),form,second.get_smallval());
	printf("%-21s| %*.2f | %*.2f \n","Mean elevation",form,first.get_mean(),form,second.get_mean());
	printf("%-21s| %*.2f | %*.2f \n","Median elevation",form,first.get_median(),form,second.get_median());
	printf("%-21s| %*.2f \n","RMSE of the files",form+(form/3),error);
	
	return 0;
}