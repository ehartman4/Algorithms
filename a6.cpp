//MORNING: segfaultingwhen it gets to the double new line char, after the word "me." lab 11 works fin soooowtf?
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Word {
	
public:
	Word(){
		text = "";
		repeatcount = 0;
	}
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
public:
	Bucket(){
		collisions = 0;
		first = NULL;
		content = 0;
	}
	Word* first;
	int collisions;
	int content;
	int addword(string);
};

int Bucket::addword(string newword)
{
	int maxcounter = 0;
	if (first==NULL)
	{
		first = new Word(newword);
		maxcounter = first->repeatcount;
		content++;
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
				maxcounter = currentword->repeatcount;
				repeat = 1;
				break;
			}
			
			lastword = currentword;
			currentword = currentword->next;
		}
		if (repeat==0)
		{
			lastword->next = new Word(newword);
			maxcounter = lastword->next->repeatcount;
			content++;
		}
	}
	return maxcounter;
}
//word counter
//pointer to first word/word instance


class hashTable{
	int tablesize;
	float A;
	Bucket* table;
	int maxfreq;
	list<string> maxiest;
public:
	hashTable(int thetablesize, float theA){
		tablesize = thetablesize;
		A = theA;
		table = new Bucket[tablesize];
		maxfreq = 0;
	}
	void insert(string);
	void printhighest();
	void biggestbucket();
	void collstats();
};

void hashTable::insert(string input)
{
	int key = 0;
	for (int i = 0; i < input.length(); i++)
	{
		key += input[i];
	}
	int mult = key*A;
	float mod1 = key*A - mult;
	int hashvalue = tablesize*mod1;
	int possmax = table[hashvalue].addword(input);
	if (possmax > maxfreq)
	{
		maxiest.clear();
		maxfreq = possmax;
		maxiest.push_back(input);
	}
	else if (possmax == maxfreq)
	{
		maxiest.push_back(input);
	}
}

void hashTable::printhighest()
{
	cout<<"Most frequent words: ";
	int limit = maxiest.size();
	for (int i = 0; i < limit; ++i)
	{
		cout<<"\""<<maxiest.front()<<"\"";
		maxiest.pop_front();
		if (maxiest.size() != 0)
		{
			cout<<", ";
		}
	}
	cout<<" Frequency: "<<maxfreq<<endl;
}

void hashTable::biggestbucket()
{
	Bucket bigbucket;
	int val = 0;
	for (int i = 0; i < tablesize; ++i)
	{
		if (table[i].content > bigbucket.content)
		{
			bigbucket = table[i];
			val = i;
		}
	}
	Word* current = bigbucket.first;
	cout<<"Most-Used Bucket: "<<val<<" Content: ";
	for (int i = 0; i < bigbucket.content; ++i)
	{
		cout<<"\""<<current->text<<"\"";
		if (i != bigbucket.content - 1)
		{
			cout<<", ";
		}
		current = current->next;
	}
	cout<<endl;
}

void hashTable::collstats()
{
	int totcoll = 0;
	for (int i = 0; i < tablesize; ++i)
	{
		totcoll += table[i].collisions;
	}
	cout<<"Total Collisons: "<<totcoll<<endl;
	cout<<"Average Collisions per Bucket: "<<(double) totcoll/tablesize<<endl;
}

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
	//myTable.insert("me\t");
	
	while(!fin.eof())
	{
		fin>>s;
		//cout<<"s "<<s<<endl;;
		myTable.insert(s);
		
		//fin.get(c);
		/*
		if (fin.peek()!='\n')
		{
			fin.get(c);
		}*/
		//cout<<s<<c;
	}
	myTable.printhighest();
	myTable.biggestbucket();
	myTable.collstats();
	return 0;
}