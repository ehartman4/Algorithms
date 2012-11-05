/*
 * sorting.cpp
 *
 * Program that implements bubble, shell, merge, and quicksort 
 * sorting algorithms.
 *
 * Input:  N, the number of random numbers to generate for sorting.
 *         choice, for choosing one of the sorting functions.
 * Output: the unsorted followed by the sorted array as well as the number
 *         of times the innermost loop executed.
 */

#include <iostream>
#include <assert.h>
using namespace std;

int counter = 0;	// number of times inner statement is executed


// Bubble sort

void
BubbleSort (int A[], int N)
{
   int i;
   int pass;   // number of current pass through array
   int temp;   // temporary for use in exchanges
   int sorted; // whether or not array is sorted

   pass = 1;

   do {
      sorted = 1;  // assume sorted until determined otherwise

      for (i = 0; i < N-pass; ++i) {
         if (A[i] > A[i + 1]) {
            // exchange out-of-order pair
            temp = A[i];
            A[i] = A [i + 1];
            A [i + 1] = temp;
            sorted = 0;
            counter++;
         }
      }
      ++pass;
   } while (! sorted);
}


// Shell sort

void
ShellSort( int A[ ], int N )
{
   for( int Gap = N / 2; Gap > 0; Gap = Gap == 2 ? 1 : (int) (Gap/2.2))
   // in english:
   // for (int Gap = 4; Gap > 0; Gap = 1) i.e., twice
   // Gap is the distance between elements.  With 8 elements, there are
   // only two gaps: 4 and then 1
      for( int i = Gap; i < N; i++ )  // just like insertion sort
      {
         int Tmp = A[ i ];
         int j = i;

         for( ; j >= Gap && Tmp < A[ j - Gap ]; j -= Gap ) {
            A[ j ] = A[ j - Gap ];
            counter++;
         }
         A[ j ] = Tmp;
      }
}

// Merge routine
//
// LeftPos = start of left half.
// RightPos = start of right half.

void
Merge( int A[ ], int TmpArray[ ], int LeftPos,
                        int RightPos, int RightEnd )
{
    int LeftEnd = RightPos - 1;
    int TmpPos  = LeftPos;
    int NumElements = RightEnd - LeftPos + 1;

    // Main loop.
    // leftpos is pointer in left half, rightpos is pointer in right half
    while( LeftPos <= LeftEnd && RightPos <= RightEnd )  {
        if( A[ LeftPos ] <= A[ RightPos ] )
            TmpArray[ TmpPos++ ] = A[ LeftPos++ ];
        else
            TmpArray[ TmpPos++ ] = A[ RightPos++ ];
        counter++;
    }

    // finishes up each side if there's some left
    while( LeftPos <= LeftEnd ) {  // Copy rest of first half. 
        TmpArray[ TmpPos++ ] = A[ LeftPos++ ];
        counter++;
    }

    while( RightPos <= RightEnd ) { // Copy rest of second half. 
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


void Swap (int &one, int &two)
{
   int tmp;
    
   tmp = one;
   one = two;
   two = tmp;
}


// Quicksort: sort first N items in array A

static const int Cutoff = 10;

void
QuickSort( int A[ ], int Low, int High )  // low/high are indexes
{
    if( Low + Cutoff > High )
        // not worth doing quicksort because of recursive overhead
        //InsertionSort( &A[ Low ], High - Low + 1 );
	ShellSort (&A [Low], High - Low + 1);
    else
    {
        // find a "good" pivot that is the median of 3 values (at
	// low,k middle, and high)

            //Sort Low, Middle, High
        int Middle = ( Low + High ) / 2;

        if( A[ Middle ] < A[ Low ] )
            Swap( A[ Low ], A[ Middle ] );
        if( A[ High ] < A[ Low ] )
            Swap( A[ Low ], A[ High ] );
        if( A[ High ] < A[ Middle ] )
            Swap( A[ Middle ], A[ High ] );

            // Place pivot at Position High-1
	// this is done because it's easier to deal with a contiguous array
        int Pivot = A[ Middle ];
        Swap( A[ Middle ], A[ High - 1 ] );
        counter++;

        // Begin partitioning
        int i, j;
        for( i = Low, j = High - 1; ; )
        {
            while( A[ ++i ] < Pivot )   // note not <= (see below)
                ;                    
            while( Pivot < A[ --j ] )   // note not <=
                ;                   
            if( i < j ) {
                Swap( A[ i ], A[ j ] );
                counter++;
	    }
            else
                break;
        }

        // Restore pivot
	// stick pivot back to position where it really belongs
        Swap( A[ i ], A[ High - 1 ] );
        counter++;

        QuickSort( A, Low, i - 1 );   // Sort small elements
        QuickSort( A, i + 1, High );  // Sort large elements
    }
}



int main ()
{
   int * array;		// array of values to sort
   int i;		// loop variable
   int n;		// desired array size
   int choice;		// menu option

   //srand (time (NULL));    // generate seed value for random number generator

   cout << "Array size -> ";
   cin >> n;
   array = new int [n];
   assert (array);
   srand (n);

   // display unsorted array
   cout << "Initial array:" << endl;
   if (n > 20)
      cout << "   Too large to display..." << endl;
   for (i = 0; i < n; i++) {
	   array [i] = rand () % 100;
	   if (n <= 20)
	      cout << array [i] << "  ";
   }
   cout << endl << endl;

   cout << "1 - Bubble sort" << endl;
   cout << "2 - Shell sort" << endl;
   cout << "3 - Merge sort" << endl;
   cout << "4 - Quick sort" << endl;
   cout << "-> ";
   cin >> choice;
   cout << endl;

   switch (choice) { 
   	case 1: BubbleSort (array, n);
		cout << "Bubble sort" << endl;
		break;
   	case 2: ShellSort (array, n);
		cout << "Shell sort" << endl;
		break;
	case 3: MergeSort (array, n);
		cout << "Merge sort" << endl;
		break;
	case 4: QuickSort (array, 0, n-1);
		cout << "Quicksort" << endl;
   }
   
   // display sorted array
   cout << "Sorted array: " << endl;
   if (n > 20)
      cout << "   Too large to display..." << endl;
   else {
      for (i = 0; i < n; i++)
         cout << array [i] << "  ";
      cout << endl;
   }

   // display counter
   cout << "Count: " << counter << endl << endl;

   return 0;
}
