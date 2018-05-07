// remove.cpp
// compile with: /EHsc
// Illustrates how to use the remove function.
//
// Functions:
//   remove - remove all elements from the sequence that match value.
//   begin - Returns an iterator that points to the first element in a
//           sequence.
//   end - Returns an iterator that points one past the end of a sequence.
//////////////////////////////////////////////////////////////////////

// disable warning C4786: symbol greater than 255 character,
// okay to ignore
#pragma warning(disable: 4786)

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main()
{
    const int VECTOR_SIZE = 8 ;

    // Define a template class vector of integers
    typedef vector<int > IntVector ;

    //Define an iterator for template class vector of integer
    typedef IntVector::iterator IntVectorIt ;

    IntVector Numbers(VECTOR_SIZE) ;   //vector containing numbers

    IntVectorIt start, end, it, last;

    start = Numbers.begin() ;   // location of first
                                // element of Numbers

    end = Numbers.end() ;       // one past the location
                                // last element of Numbers

    //Initialize vector Numbers
    Numbers[0] = 10 ;
    Numbers[1] = 20 ;
    Numbers[2] = 10 ;
    Numbers[3] = 15 ;
    Numbers[4] = 12 ;
    Numbers[5] = 7 ;
    Numbers[6] = 9 ;
    Numbers[7] = 10 ;


    cout << "Before calling remove" << endl ;

    // print content of Numbers
    cout << "Numbers { " ;
    for(it = start; it != end; it++)
        cout << *it << " " ;
    cout << " }\n" << endl ;

    // remove all elements from Numbers that match 10
    last = remove(start, end, 10) ;

    cout << "After calling remove" << endl ;

    // print content of Numbers
    cout << "Numbers { " ;
    for(it = start; it != end; it++)
        cout << *it << " " ;
    cout << " }\n" << endl ;

    //print number of elements removed from Numbers
    cout << "Total number of elements removed from Numbers = "
         << end - last << endl ;

    //print only the valid elements of Number
    cout << "Valid elements of Numbers { " ;
    for(it = start; it != last; it++)
        cout << *it << " " ;
    cout << " }\n" << endl ;

}
