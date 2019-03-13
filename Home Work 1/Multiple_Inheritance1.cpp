/*
CH08-320143
a1 p3.cpp
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
  void setX(int i) {x = i;}
  void print() { cout << x; }
};

class B: virtual public A //virtual inheritance from A
{
public:
  B()  { setX(10); }
};

class C: virtual public A  //virtual inheritance from A
{
public:
  C()  { setX(20); }
};

class D: public B, public C {
};

int main()
{
    D d;
    d.print();
    return 0;
}

//************GENERATED ERROR**********
/*exit status 1
main.cpp:30:7: error: non-static member 'print' found in multiple base-class subobjects of type 'A':
    class D -> class B -> class A
    class D -> class C -> class A
    d.print();
      ^
main.cpp:9:8: note: member found by ambiguous name lookup
  void print() { cout << x; }
       ^
1 error generated.
*/

//********EXPLANATION TO SOLUTION********
/*
Ambiguity arrises when two classes inherit from one class in this case, B&C both inherit from A,
and another class, in this case D, also inherits from both B and C.
To solve the ambiguity, virtual inheritance has to be used, such that class A is virtually inherited.
*/
