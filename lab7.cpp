#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

using namespace std;

void number1(){
    cout<<"Type characters: ";
    char a;
    int count = 1;
    while (a != 'z'){
        cin>>a;
        if (count%3==0 and a!='z'){
            cout<<a<<endl;
        }
        count += 1;
    }
    cout<<"Done"<<endl;
}

void number3(){
    cout<<"Give two numbers, separated by a new line: ";
    int one,two;
    cin>>one;
    cin>>two;
    int product = one*two;
    int remainder = one%two;
    int quotient = (one-remainder)/two;
    cout<<'\t'<<setw(6)<<one<<'\t'<<'\t'<<'\t'<<'\t'<<setw(9)<<quotient<<setw(4)<<'R'<<setw(4)<<remainder<<endl;
    cout<<'\t'<<'x'<<setw(5)<<two<<'\t'<<'\t'<<'\t'<<'\t'<<setw(9)<<"-----"<<endl;
    cout<<'\t'<<"------"<<'\t'<<'\t'<<'\t'<<'\t'<<setw(3)<<two<<setw(2)<<')'<<setw(4)<<one<<endl;
    cout<<'\t'<<setw(6)<<product<<endl;
    /*
    printf("\t %5i\t\t\t\t    %5i   %c   %i\n", one, quotient,'R',remainder);
    printf("\t%c%5i\t\t\t\t    %c%c%c%c%c\n", 'x', two,'-','-','-','-','-');
    printf("\t%c%c%c%c%c%c\t\t\t\t%3i %c%4i\n",'-','-','-','-','-','-', two,')',one);
    printf("\t%6i\n", product);
    */
}



int main(){
    //int argc,char* argv[20]
    //number1();
    /*
    ifstream inf;
    inf.open(argv[1]);
    if (fopen(argv[1], "r") == NULL){
        cout<<"This file does not exist."<<endl;
    }
    else{
        char c;
        inf.get(c);
        while (!inf.eof()){
            cout<<c;
            inf.get(c);
        }
    }
    */
    number3();
    //cout<<setw(10)<<77<<endl;
    return 0;
}
