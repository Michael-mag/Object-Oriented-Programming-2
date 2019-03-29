/*
    CH08-320143
    testfraction.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de


*/
#include "fraction.h"
using namespace std;

int nPass = 0;
int nFail = 0;
void test( bool i)
{
    if(i)
    {
        nPass++;
    }
    else
    {
        nFail++;
    }
}
int main()
{
    string f_invalid_in ="1-23/-253";


    cout<<"TEST_ Input/Output Operators :"<<endl;
    Fraction Test_in;
    try
    {
        cin>>Test_in;
        nPass++;
    }
    catch(string* msg)
    {
        cout<<*msg<<endl;
        nFail++;
    }
    //Result
    cout<<"Passed : "<<nPass<<"    Failed : "<<nFail<<endl;
    nPass=nFail=0;

    Fraction A(1,2),B(2,1);
    cout<<"A = "<<A<<"\nB = "<<B<<endl;
    cout<<endl<<"TEST_ Arrithmetic Operators :"<<endl;
    //need try and catch for Fraction::Fraction(int.int)
    try
    {
        test((A + B) == Fraction(5,2));
        test((A - B) == Fraction(-3,2));
        test((A * B) == Fraction(2,2));
        test((A / B) == Fraction(1,4));
    }
    catch (string msg)
    {
        //The obove should be valid
    }
    //Result
    cout<<"Passed : "<<nPass<<"    Failed : "<<nFail<<endl;
    nPass=nFail=0;

    cout<<endl<<"TEST_ Relational Operators :"<<endl;
    test(A<B);
    test(A<=B);
    test((A>B) == false);
    test ((A>=B) == false);
    test ((A==B) ==false);
    test (A!=B);

    //Result
    cout<<"Passed : "<<nPass<<"    Failed : "<<nFail<<endl;
    nPass=nFail=0;

    cout<<endl<<"TEST_ Assignment & Fraction(Fraction) :"<<endl;
    Fraction Copy_A(A);
    cout<<"Copy_A = "<<A<<endl;
    A = B;
    cout<<"A = B; A = "<<A<<endl;

    cout<<endl<<"TEST_ Exception Handling :"<<endl;
    // Fraction(int,int)

    try
    {
        Fraction C(23,0);//den. = 0 => undefined
        nFail++;//if line is processed, then report fail
    }
    catch(string *msg)
    {
        cout<<*msg<<endl;
        nPass++;//Pass since exception handling worked
    }

    //Fraction(string)
    try
    {
        Fraction D(f_invalid_in);
        nFail++;//Fail, since exception handling would have failed
    }
    catch (string* msg)
    {
        cout<<*msg<<endl;
        nPass++;//Pass since exception handling worked
    }
    cout<<"Passed : "<<nPass<<"    Failed : "<<nFail<<endl;

    return 0;

}
