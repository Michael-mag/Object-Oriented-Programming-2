/*
    CH08-320143
    a3_p3.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
*/

#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    int in[100];
    //1
    list<int> A,B;
    fstream B_out;
    B_out.open("listB.txt",fstream::out);
    if(!B_out.is_open())
    {
        exit(-1);
    }

    list<int>::iterator itA,itB;

    itA = A.begin();

    int n = 0;
    //2. Input
    do
    {
        cin>>in[n];
        n++;
    }
    while(in[n - 1] > 0);

    n--;
    //3. Insert to A to the end
    A.insert(itA,in,in+n);

    //4. inserting to B from the beginnig is the same as reversing A:
    B = A;
    B.reverse();

    //5.1 Print A
    for(itA = A.begin(); itA != A.end(); itA++)
    {
        cout<<*itA<<" ";
    }
    cout<<endl;

    //5.2 Print B to file
    for(itB = B.begin(); itB != B.end(); itB++)
    {
        B_out<<*itB<<" ";
    }

    //6. print new line
    cout<<endl;

    //7. Move front to end
    A.push_back(*A.begin());
    A.pop_front();
    B.push_back(*B.begin());
    B.pop_front();

    //8.1 print A
    itA = A.begin();
    cout<<*itA;
    for( itA++; itA != A.end(); itA++)
    {
        cout<<","<<*itA;
    }
    cout<<endl;

    //8.2 print B
    itB = B.begin();
    cout<<*itB;
    for( itB++; itB != B.end(); itB++)
    {
        cout<<","<<*itB;
    }

    //9
    cout<<endl<<endl;

    //10 Merge B into A
    A.merge(B);

    //11.1 Sort A
    A.sort();

    //11.2 Print A
    for(itA = A.begin(); itA != A.end(); itA++)
    {
        cout<<*itA<<" ";
    }
    cout<<endl;

    B_out.close();

    return 0;
}
