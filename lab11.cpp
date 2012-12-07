#include <iostream>
#include <fstream>
//#include <array>
using namespace std;

/*
class adjlist
{
public:

};
*/
int printdoc()
{
	char filename[80];
	cout<<"Filename: ";
	cin>>filename;
	fstream fin;
	fin.open(filename);
	string s;
	char c;
	while(!fin.eof())
	{
		fin>>s;
		//fin.get(c);
		cout<<s<<endl;
		//cout<<s<<c;
	}
	return 0;
}

int main()
{
	printdoc();
	/*
	cout<<"edges: ";
	int adjmatrix[26][26];
	int edgesize = 0;
	for (int k = 0; k < 26; ++k)
	{
		for (int l = 0; l < 26; ++l)
		{
			adjmatrix[k][l] = -1;
		}
	}
	//adjmatrix.fill(-1);
	char a,b,c;
	int weight,i,j;
	cin>>a>>b>>weight;
	cin.get(c);
	
	while(a != b){
		edgesize++;
		i = a;
		j = b;
		if (a<b){
			adjmatrix[i-65][j-65] = weight;
		}
		else{
			adjmatrix[j-65][i-65] = weight;
		}
		cin>>a>>b>>weight;
		cin.get(c);
	}
	char d,e;
	for (int i = 0; i < 26; ++i)
	{
		for (int j = i; j < 26; ++j)
		{
			if (adjmatrix[i][j]!=-1)
			{
				d = i + 65;
				e = j + 65;
				cout<<"Vertex: "<<d<<" "<<e<<" Weight: "<<adjmatrix[i][j]<<endl;
			}
		}
	}
	cout<<endl;
	int locmini, locminj, minval = -1;
	for (int k = 0; k < edgesize; ++k)
	{
		for (int i = 0; i < 26; ++i)
		{
			for (int j = i; j < 26; ++j)
			{
				if (adjmatrix[i][j]!=-1)
				{
					if (minval == -1 or adjmatrix[i][j] < minval)
					{
						locmini = i;
						locminj = j;
						minval = adjmatrix[i][j];
					}
				}
			}
		}

		d = locmini + 65;
		e = locminj + 65;
		cout<<"Vertex: "<<d<<" "<<e<<" Weight: "<<minval<<endl;
		adjmatrix[locmini][locminj] = -1;
		minval = -1;
	}
	*/
	return 0;
}