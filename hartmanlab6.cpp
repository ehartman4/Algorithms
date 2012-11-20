#include <iostream>

using namespace std;

//computing the sum given in question 1 part (a)
int q1(int n){
    int sum = 0;
    for (int i=2;i<=n;i++){
        sum += n + (3*i);
    }
    return sum;
}

//the code in question 2
int sum2(int n){
    int count = 0;
    int i, j;
    int x = 0;
    for (int i=0;i<n;i++){
        if (i%2){
            for (j = 1; j<=i; j++){
                x = x+(n*j);
                count ++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter any n: ";
    cin>>n; //this n is then used for both a result for question 1 and in the code for question 2, producing a count result of how many time x is changed.
    int result = q1(n);
    cout<<"Summation Result of question 1: "<<result<<endl;
    int result2 = sum2(n);
    cout<<"Counting Result of question 2: "<<result2<<endl;
    return 0;
}
