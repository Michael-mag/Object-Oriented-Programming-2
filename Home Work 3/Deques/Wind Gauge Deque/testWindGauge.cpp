/*
    CH08-320143
    a3_p5.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
*/
#include <iostream>
#include <deque>
#include "WindGauge.h"

using namespace std;

void Print(WindGauge &A)
{
    cout<<"Highest :"<<A.highest()<<endl;
    cout<<"Lowest  :"<<A.lowest()<<endl;
    cout<<"Average :"<<A.average()<<endl;
}

int main()
{
   //Create obj
    WindGauge A;
    int speeds1[] = {15, 16, 12, 15, 15};
    int speeds2[] = {16, 17, 16, 16, 20, 17, 16, 15, 16,20};
    int i;
   //2.1 Add first 5 speeds
    for(i = 0 ; i < 5; i++)
        A.currentWindSpeed(speeds1[i]);

    //2.2
    Print(A);
    cout<<endl;

   //3.1 Add 10 more measurements
    for (i = 0; i < 10; i++)
        A.currentWindSpeed(speeds2[i]);

   //3.2
    Print(A);
    cout<<endl;

    return 0;
}
