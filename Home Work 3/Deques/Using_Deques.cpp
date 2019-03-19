/*
    CH08-320143
    a3_p4.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
*/
#include <iostream>
#include <deque>
 using namespace std;
int main()
{
    //1. Create deque A
    deque<float> A;
    deque<float>::iterator it;
    float in[100];
    int n = -1,i;

    //2. Read floats until 0 is entered
    do
    {
        n++;
        cin>>in[n];
    }
    while(in[n] != 0);

    //3.
    for(i = 0; i < n; i++)
    {
        if(in[i] > 0)
        {
            //3.1 Insert positive elements at the end of A
            A.push_back(in[i]);
        }
        else
        {
            //3.2 Insert negative elements at the beginning of A
            A.push_front(in[i]);
        }
    }

    //4 Print
    for ( it = A.begin();it != A.end() ; it++)
    {
        cout<<*it<<" ";
    }

    //5 Print empty line
    cout<<endl<<endl;

    //6 Add 0 between last negative element and first positive element
    it = A.begin();
    while(it != A.end())
    {
        if (*it > 0 && it != A.begin())
        {
            //only insert 0 if both - and + exist
            A.insert(it,0);
            break;
        }
        it++;
    }

    //7 Print
    it = A.begin();
    cout<<*it;
    for (it++; it != A.end() ; it++)
    {
        cout<<";"<<*it;
    }

    cout<<endl;
    return 0;
}
