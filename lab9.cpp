#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class hashTable {
	int* hasharray;
	int totalstored;
	int arraysize;
public:
	hashTable(int insize){
		arraysize = insize;
		hasharray = new int [arraysize];
		for (int i = 0; i < arraysize; ++i)
		{
			hasharray[i] = -1;
		}
		totalstored = 0;
	}
	void insert(int);
	void display();
	void readin(char []);
};

void hashTable::insert(int newval)
{
	int hashval = newval % arraysize;
	while(hasharray[hashval] > -1)
	{
		hashval++;
		if (hashval == arraysize)
		{
			hashval = 0;
		}
	}
	hasharray[hashval]=newval;
	totalstored++;
	//cout<<"hashval "<<hashval<<endl;
}

void hashTable::display(){
	for (int i = 0; i < arraysize; ++i)
	{
		if ((i) % 10 == 0)
		{
			cout << endl;
		}
		if (hasharray[i] > -1)
		{
			cout << setw(5) << hasharray[i];
		}
		else
		{
			cout << setw(5) << "X";
		}
	}
}

void hashTable::readin(char filename[80]){
	
	ifstream fin;
	fin.open(filename);
	int i;
	int count = 0;
	while (!fin.eof() and count<arraysize)
	{
		fin>>i;
		insert(i);
		count ++;
	}
	if (count==arraysize)
	{
		cout<<"Hash table is full"<<endl;
	}

}

int main()
{
	
	char filename[80];
	cout<<"File name: ";
	cin>>filename;
	int size;
	cout<<"Table size: ";
	cin>>size;
	hashTable ourTable(size);
	ourTable.readin(filename);
	/*
	ourTable.insert(0);
	
	ourTable.insert(19);
	ourTable.insert(39);
	
	ourTable.insert(4);
	ourTable.insert(4);
	ourTable.insert(5);
	ourTable.insert(25);
	ourTable.insert(24);
	ourTable.insert(0);
	*/
	ourTable.display();
	return 0;
}