/*
CH08-320143
a1 p4.cpp
Michael Magaisa
m.magaisa@jacobs-university.de
*/

//****EXPLANATION AT THE END********

#include<iostream>
using namespace std;

class A
{
  int x;
public:
  A(int i) { x = i; }
  void print() { cout << x; }
};

class B: virtual public A
{
public:
  B():A(10) {  }
};

class C:  virtual public A
{
public:
  C():A(10) {  }
};

class D: public B, public C {
public:
  D() : A(10) ,B(), C(){
    //Explicit contruction call
  }
};

int main()
{
    D d;
    d.print();
    return 0;
}


//*********GENERATED ERROR MESSAGE**********
/*
exit status 1
main.cpp:29:7: error: call to implicitly-deleted default constructor of 'D'
    D d;
      ^
main.cpp:12:10: note: default constructor of 'D' is implicitly deleted because
base class 'A' has no default constructor
class B: virtual public A
         ^
1 error generated.
*/

 //**********EXPLANATION TO SOLUTION**********
 /*
The compiler could not implicitly call the constructor of A because it has an
explicit constructor which has a parameter.To avoid implicit call, explicitly
call a constructor from class D, since D has no concept of a constructor.
 */
