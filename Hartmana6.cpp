/*
File name:		hartmana6.cpp
Date:			December 7, 2012
Name:			Emma Hartman
Description:	Stores words from an input stripped text file in a hash table. Returns statistics on collisions and most frequently used buckets.
Input:			A plain ASCII text file stripped of punctuation and uppercase letters, a user-selected table size for the hash (integer, preferably prime), and a user-selected has constant A, where A is a real number and 0<A<1.
Output: 		In a well-formatted manner, outputs the word or words with highest frequency in the text file along with that word count, the contents of the bucket that was hasehd to most often (most used bucket), the total number of collisions, and the average number of collisions per bucket.
*/

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

//class for each individual word in the hash table
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

//structure for each "bucket", or index, in the table.
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


/*
Description: Once it has been determined which bucket a word should be hashed to, this method adds the word to that bucket.
Pre-Condition: A word that hashes to the bucket specified.
Post-Condition: The word has been added to the bucket. If the word is not already in the bucket, it is as added to the end of the bucket list. If the word is already in the bucket, the count for that word is updated. Either way, the number of collisions is updated (unless this is the first item added to an empty bucket).
*/
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

/*
Description: Finds the appropriate spot for a string to hash to in the hash table, calls the Bucket::addword() method to actually add that word to the hash table. Also updates the value keeping track of the word most frequently used in the file. Checks to see if the word being input is now used more frequently than what is so far the most frequently used word.
Pre-Condition: A string to be added to the given hash table.
Post-Condition: The hash function has been run on the input string, and the addword() method of Bucket has added the word (string) to the appropriate bucket and therefore to the hash table. If the word's frrequency is greater than that of the current highest frequency word in the hash table, that value has been updated.OR if the word has the same frequency as the highest frequency word, that word is added to the max frequency list.
*/
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

/*
Description: Prints out all the most frequently stored words in the hash table and their shared frequency.
Pre-Condition: A hash table exists with a table size and hashing constant A having been chosen. Presumably, words have been inserted into the hash table, though this is not necessary for it to run.
Post-Condition: Prints out the word stored most frequently in the hash table, in the order in which the last instance of each word was inserted into the table, separated by commas. Also prints the shared frequency of these words.
*/
void hashTable::printhighest()
{
	cout<<"Most frequent word(s): ";
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

/*
Description: This method prints the contents of the bucket that stores the most words.
Pre-Condition: A hash table exists with a table size and hashing constant A having been chosen. Presumably, words have been inserted into the hash table, though this is not necessary for it to run.
Post-Condition: Prints out the number (index) in the table of the bucket containing the most words, and prints out all the words contained in that bucket. Most words refers to most UNIQUE words. Multiple copies of the same word do not increase change the "size" of the bucket for this count's purposes.
*/
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

/*
Description: This method prints out statistics regarding collisions in the hash table: the total number of collisions and the average collisons/bucket.
Pre-Condition: A hash table exists with a table size and hashing constant A having been chosen. Presumably, words have been inserted into the hash table, though this is not necessary for it to run.
Post-Condition: Prints out the total number of collisions that occur in the hash table, and the average collisions that happen per bucket (tablesize).
*/
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
	
	while(!fin.eof())
	{
		fin>>s;
		myTable.insert(s);
	}
	myTable.printhighest();
	myTable.biggestbucket();
	myTable.collstats();
	return 0;
}