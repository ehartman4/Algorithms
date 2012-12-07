#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	char filename[80];
	cout<<"Filename: ";
	cin>>filename;
	ifstream fin;
	fin.open(filename);
	float debit,credit,val;
	char c;
	debit=credit=val=0;
	cout<<left<<setw(30)<<"Activity";
	cout<<right<<setw(10)<<"Debit"<<setw(10)<<"Credit"<<endl;
	fin>>val;
	if (val<0)
	{
		debit=val;
	}
	else {credit = val;}
	cout<<left<<setw(30)<<"Beginning Balance";
	if (val>0)
	{
		cout<<right<<fixed<<setw(10)<<" "<<setw(10)<<setprecision(2)<<val<<endl;
	}
	else
	{
		cout<<right<<fixed<<setw(10)<<setprecision(2)<<val<<endl;
	}
	fin.get();
	int count;
	while (!fin.eof())
	{
		float temp;
		fin>>val;
		fin.get(c);
		while (c==',')
		{
			val *= 1000;
			fin>>temp;
			val += temp;
			fin.get(c);
		}
		count = 0;
		if (c=='+')
		{
			credit+=val;
			fin.get(c);
			while (c!='\n' && !fin.eof())
			{
				cout<<c;
				count++;
				fin.get(c);
			}
			cout<<setw(30-count)<<" "<<fixed<<setw(10)<<" "<<setw(10)<<setprecision(2)<<val<<endl;
		}
		else
		{
			debit+=val;
			fin.get(c);
			while (c!='\n' && !fin.eof())
			{
				cout<<c;
				count++;
				fin.get(c);
			}
			cout<<setw(30-count)<<" "<<fixed<<setw(10)<<setprecision(2)<<val<<endl;
		}
	}
	cout<<setw(30)<<" "<<"----------  ----------"<<endl;
	cout<<left<<setw(30)<<"Subtotals:"<<right<<setw(10)<<setprecision(2)<<debit<<setw(10)<<setprecision(2)<<credit<<endl;
	cout<<left<<setw(30)<<"Final Balance:";
	float final = credit - debit;
	if (final>0)
	{
		cout<<right<<setw(10)<<" "<<setw(10)<<setprecision(2)<<final;
	}
	else{
		cout<<right<<setw(10)<<setprecision(2)<<final;
	}
	return 0;
}