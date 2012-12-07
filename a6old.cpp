#include <iostream>
#include <fstream>

using namespace std;

class Word {
	
public:
	Word(){}
	Word(string thetext){
		text = thetext;
		repeatcount = 1;
		next = NULL;}
	int repeatcount;
	string text;
	Word* next;
};
//pointer to next word, default to null
//repeat wordcounter

class Bucket {
	Word* first;
public:
	Bucket(){
		collisions = 0;
		first = NULL;
		maxword = NULL;
	}
	Word* maxword;
	int collisions;
	void addword(string);
};

void Bucket::addword(string newword)
{
	if (first==NULL)
	{
		first = new Word(newword);
	}
	else
	{
		collisions++;
		Word* lastword;//might need to create second copy constructor for this to work
		Word* currentword = first;
		bool repeat = 0;
		while(currentword != NULL)
		{
			if (currentword->text == newword)
			{
				currentword->repeatcount++;
				if (currentword->repeatcount > maxword->repeatcount)
				{
					maxword = currentword;
				}
				repeat = 1;
				break;
			}
			lastword = currentword;
			currentword = currentword->next;
		}
		if (repeat==0)
		{
			lastword->next = new Word(newword);
		}
	}
}
//word counter
//pointer to first word/word instance


class hashTable{
	int tablesize;
	float A;
	Bucket* table;
public:
	hashTable(int thetablesize, float theA){
		tablesize = thetablesize;
		A = theA;
		table = new Bucket[tablesize];
	}
	void insert(string);
	void printhighest();
};

void hashTable::insert(string input)
{
	int key = 0;
	cout<<input;
	for (int i = 0; i < input.length(); i++)
	{
		key += input[i];
	}
	cout<<key<<endl;
	int mult = key*A;
	float mod1 = key*A - mult;
	int hashvalue = tablesize*mod1;
	cout<<hashvalue<<endl;
	table[hashvalue].addword(input);
}
/*
void hashTable::printhighest()
{
	Word *maxiest = new Word;
	for (int i = 0; i < tablesize; ++i)
	{
		if (table[i].maxword->repeatcount > maxiest->repeatcount)
		{
			maxiest = table[i].maxword;
		}
	}
	cout<<"Most frequent word: "<<maxiest->text<<" Frequency: "<<maxiest->repeatcount<<endl;
}
*/
int main(){
	char filename[80];
	int thetablesize;
	float theA;
	cout<<"Filename: ";
	cin>>filename;
	cout<<"Size of the hash table: ";
	cin>>thetablesize;
	cout<<"Hash constant: ";
	cin>>theA;
	hashTable myTable(thetablesize,theA);
	fstream fin;
	fin.open(filename);
	string s;
	//char c;
	while(!fin.eof())
	{
		fin>>s;
		myTable.insert(s);
		//fin.get(c);
		//cout<<s<<c;
	}
	return 0;
}