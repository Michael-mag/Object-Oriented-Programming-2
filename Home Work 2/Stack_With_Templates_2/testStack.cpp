/*
    CH08-320143
    a2_p3.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
Template Stack;
*/
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
int main()
{
    Stack<int> intStack;//Empty constructor
    Stack<string> charStack(10);//Constructor to set size

    int i;
    int out_int;
    string out_str;

    string Str = "a";//used to create strings for charStack
    char b = 'b';

    //Creating some elements
    cout<<"Top elements of Stack"<<endl;
    cout<<"    Int    String"<<endl;
    for (i = 0; i < 10; i++)
    {
        intStack.push(i+1);
        Str+= b+i;
        charStack.push(Str);

        cout<<"Top: "<<intStack.back()<<"   "<<charStack.back()<<endl;
    }
    //Using the added functionality
    intStack.resize(15);
    cout<<"\nExtended Int Stack, Size of Stack = "<<intStack.getSize()<<endl;
    cout<<"num entries in int Stack: "<<intStack.getNumEntries()<<endl;
    cout<<"Int stack after setting size to 15:"<<endl;
    int max =intStack.getNumEntries();
    for (i = 0; i <  max; i++)//Print to std output
    {
        intStack.pop(out_int);
        cout<<"out : "<<out_int<<endl;
    }
    cout<<endl;
    cout<<"After poping elements, size = "<<intStack.getSize()<<" ";
    cout<<",No. of elements = "<<intStack.getNumEntries()<<endl;
    cout<<endl;

    charStack.resize(5);
    cout<<"Shrunk String Stack, Size of Stack = "<<charStack.getSize()<<endl;
    cout<<"num entries in String Stack: "<<charStack.getNumEntries()<<endl;
    cout<<"String stack after setting size to 5"<<endl;
    max = charStack.getNumEntries();
    for (i = 0; i <  max; i++)//Print
    {
        charStack.pop(out_str);
        cout<<"out : "<<out_str<<endl;
    }

    cout<<endl;
    cout<<"After poping elements, size = "<<charStack.getSize()<<" ";
    cout<<",No. of elements = "<<charStack.getNumEntries()<<endl;
    return 0;
}
