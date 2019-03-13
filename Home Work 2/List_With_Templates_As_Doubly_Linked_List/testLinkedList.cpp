/*
    CH08-320143
    a2_p4.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

Illustrating the Doubly linked list.

             Doubly Linked List
        ----<----<---<-----------------
back -> \ 0 \ 1 \ 2 \  ....       \ n \  <-front
        ___>____>___>_____________>____
                                    ^
                                  count

*/
#include <iostream>
#include "LinkedList.h"


int main()
{
    DoubleLinked<int> intlist;
    int i;
    //Create a list of 10 elements
    for(i = 5; i > -1; i--)
    {
        intlist.push_back(i);//adding to back
    }
    for(i = 6; i < 10; i++)
    {
        intlist.push_front(i);//adding from front
    }
    cout<<"The original "<<intlist.getSize()<<" elements are"<<endl;
    intlist.Print();

    cout<<"\nfront element : "<<intlist.getfront()<<endl;
    cout<<"back element: "<<intlist.getback()<<endl;

    cout<<"\nRemoved from front: "<<intlist.pop_front()<<endl;
    cout<<"Number of elements in List: "<<intlist.getSize()<<endl;
    cout<<"Removed from back: "<<intlist.pop_back()<<endl;

    cout<<"\nRemoving the following from back :"<<endl;
    for(i = 0; i < 5; i++)
    {
        cout<<intlist.pop_back()<<" ";
    }
    cout<<endl;

    cout<<"\nNumber of elements Left in List: "<<intlist.getSize()<<endl;
    cout<<"The remaining elements are :"<<endl;
    intlist.Print();
    cout<<endl;
    return 0;
}
