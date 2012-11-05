#include <iostream>
//#include <tuple>
#include <vector>

using namespace std;

#include <stdio.h>

void
Merge( int A[ ], int TmpArray[ ], int LeftPos,
                        int RightPos, int RightEnd )
{
    int LeftEnd = RightPos - 1;
    int TmpPos  = LeftPos;
    int NumElements = RightEnd - LeftPos + 1;

    // Main loop.
    // leftpos is pointer in left half, rightpos is pointer in right half
    while( LeftPos.first <= LeftEnd.first && RightPos.first <= RightEnd.first )  {
        if( A[ LeftPos.first ] <= A[ RightPos.first ] )
            TmpArray[ TmpPos++ ] = A[ LeftPos++ ];
        else
            TmpArray[ TmpPos++ ] = A[ RightPos++ ];
        counter++;
    }

    // finishes up each side if there's some left
    while( LeftPos.first <= LeftEnd.first ) {  // Copy rest of first half. 
        TmpArray[ TmpPos++ ] = A[ LeftPos++ ];
        counter++;
    }

    while( RightPos.first <= RightEnd.first ) { // Copy rest of second half. 
        TmpArray[ TmpPos++ ] = A[ RightPos++ ];
        counter++;
    }

    // Copy TmpArray back.
    for( int i = 0; i < NumElements; i++, RightEnd-- )
        A[ RightEnd ] = TmpArray[ RightEnd ];
}

// MergeSort: sort first N items in array A
//
// Recursive Mergesort and Merge are supporting routines

void
MergeSort( int A[ ], int TmpArray[ ], int Left, int Right )
{
    if( Left < Right ) {
        int Center = ( Left + Right ) / 2;

        MergeSort( A, TmpArray, Left, Center );
        MergeSort( A, TmpArray, Center + 1, Right );
        Merge( A, TmpArray, Left, Center + 1, Right );
    }
}

void
MergeSort( int A[ ], int N )
{
  try
  {
    int *TmpArray = new int [ N ];
    MergeSort( A, TmpArray, 0, N - 1 );
    delete [ ] TmpArray;
  }

  catch( ... )
  {
    cerr << "Out of memory!! Sort fails." << endl;
  }
}


int main ()
{
  /*
  FILE * pFile;

  pFile = fopen ("myfile2.txt","r");
  //fprintf (pFile, "%f %s", 3.1416, "PI");
  //rewind (pFile);
  vector<int> myints;
  int count =0;
  while (!feof(pFile)){
  	fscanf (pFile, "%i", myints[count]);
  	count += 1;
  fscanf (pFile, "%s", str);
  fclose (pFile);
  printf ("I have read: %f and %s \n",f,str);
  */
  pair<int,int> xi (4,5);
  vector<pair<int,int> > x;
  cout<<xi.first<<xi.second<<endl;


  //x.push_back(tuple<int,int> (3,4));

  return 0;
}