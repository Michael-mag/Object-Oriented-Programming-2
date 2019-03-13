/*
    CH08-320143
    a2_p1.cpp
    Michael Magaisa
    m.magaisa@jacobs-university.de
Template function to find element in arr;
*/

#include <iostream>
#include "Complex.h"
#define SIZE 5
using namespace std;

template <typename T>
int array_search(T A[],int n,T find)
{
    int i;
    for(i  = 0; i < n ; i++)
    {
        if(A[i] == find)
            return i;
    }
    return -1;
}

int main()
{
    int i;

    //Test on different types
    int arr_int[SIZE];
    double arr_float[SIZE];
    Complex carr[SIZE] ;

    Complex Find;//Sample Complex elem to find

    for( i  = 0 ; i < SIZE; i++)
    {
        arr_int[i] = i * 2;//arr of even int
        arr_float[i] = i*2.43;//multiples of 2.43
        carr[i] = Complex(i,SIZE - i);
    }
    Find = carr[3];

    cout << "Find 5 in int[]: "<< array_search(arr_int,SIZE,5) <<endl;
    cout << "Find 2.43*2 in float[]: "<< array_search(arr_float,SIZE,2.43*2);
    cout<<endl;
    cout << "Find Complex(3,4) in complex[]: "<< array_search(carr,SIZE,Find);
    cout<<endl;
    return 0;
}
