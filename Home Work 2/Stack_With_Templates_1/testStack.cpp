/*
    CH08-320143
    a2_p2.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
Template Stack;
*/
#include <iostream>
#include <string>
#include <iomanip>//to display bool as string instead of int
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

    cout<<"\nPush to full Int Stack: "<<boolalpha<<intStack.push(11)<<endl;

    //Pop(out)
    cout<<"\nPop Elements from Stack"<<endl;
    cout<<"    Int    String"<<endl;
    for(i = 0; i < 10 ; i++)
    {
        intStack.pop(out_int);
        charStack.pop(out_str);

        cout<<"out :"<<out_int<<"   "<<out_str<<endl;

    }

    cout<<"\nnum entries in int Stack: "<<intStack.getNumEntries()<<endl;
    cout<<"Push to empty int Stack: "<<intStack.push(400)<<endl;
    cout<<"num entries in int Stack: "<<intStack.getNumEntries()<<endl;
    cout<<"Pop from empty String Stack: "<<charStack.pop(out_str)<<endl;

    return 0;
}
