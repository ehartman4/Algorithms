//import string
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fin;
    fin.open(filename);
    
    //outfile=open("essaystrip.txt","w")
    text = infile.read()
    for i in range(len(text)):
        for j in range(len(string.punctuation)):
            if text[i] == string.punctuation[j]:
                text = text[:i] + text[(i+1):]
                break
    print(text)
    #string.lower
    
    return 0;
}