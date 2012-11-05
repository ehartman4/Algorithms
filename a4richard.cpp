#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;



int makeline(){
	float slope = (float) (two.second - one.second)/(two.first - one.first);
	float A = slope;
	float B = -1;
	float C = (-1*slope*one.first)+one.second;
}


float distance(){
	float dist;
	float top = abs((A*point.first)+(B*point.second)+C);
	float bottom = sqrt(A*A +B*B);
	distance = top/bottom;
	return dist;
}

int det(pair<int,int> point){
	int x = (a.first)*(b.second);
	x += (point.first)*(b.first);
	x += (b.first)*(point.second);
	x -= (point.first)*(b.second);
	x -= (b.first)*(a.second);
	x -= (a.first)*(point.second);
	return x;
}

int main(){
	vector< pair<int,int> > values;
	char filename [80];
	int x, y, lines;
	//, i=1;
	cout << "Please enter a filename: ";
	cin >> filename;
	ifstream read("a4.txt");
	read >> lines;
	//int xvals[lines], yvals[lines];
	while(read >> x >> y){
		cout << x << "  " << y << endl;
		values.push_back(make_pair(x, y));
		/*
		xvals[i] = x;
		yvals[i] = y;
		i++;
		*/
	}
	sort(values.begin(), values.end());
	for (int i = 0; i < values.size(); ++i)
	{
		cout << values[i].first << "  " << values[i].second << endl;
	}
	return 0;
}