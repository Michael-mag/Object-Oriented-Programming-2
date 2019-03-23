/*
    CH08-320143
    debug2.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
EXPLANATION AT THE BOTTOM

*/

#include <iostream>
#include <sstream>
using namespace std;

void foo(int *array, int n, int *positives) {
	for(int i=0; i<n; i++)//Break
		if (array[i] > 0)
			(*positives)++;//* ++ has higher priority
}

class Test {
	private:
		int *a;
		int n;
	public:
		Test() {
			a=NULL;
			n=0;
		}
		Test(int *a, int n) {
			this->n = n;
			if (this->a != NULL) {
				delete this->a;
			}
			this->a = new int[n];
			for(int i=0; i<n; i++)
		 		this->a[i] = a[i];
		}
		string toString() {
			ostringstream ss;
			ss << "Length: " << n << endl << "Elements: ";
			for(int i=0; i<n; i++)//Break
				ss << a[i] << " ";
			ss << endl;
			return ss.str();
		}
		~Test() {
			delete a;
		}
};

int main() {
	int v[3] = {1, 2, 3};
	int p=0;
	foo(v, 3, &p);
	cout << "Amount of positive values in the array=" << p << endl;
	Test arr[5];
	Test *obj1;//pointer to static var arr[0]
	obj1 = &arr[0];
	Test *obj2 = new Test(v, 3);
	//Test *obj3; //This is a pointer with no adress
	cout << obj1->toString();
	cout << obj2->toString();
	//cout << obj3->toString();//
	//delete obj1;
	delete obj2;
	//delete obj3;
	return 0;
}
/***********************EXPLANATION************************************

->put a break point at line 15 , noticed that print *positives returned random
numbers. After investigating the priority of operators, changed line 8.

->put break point in Test::toString():
  - noticed segmentation fault when obj3->toString was called [line 63]
   ->put break point at line 41:
     -print n {for obj3} resulted in a very large number, so we actually enter
     the for  loop

     -print *a {for obj 3} , gdb reported 'Cannot access memory at areass '0x...'
     ,as such since I couldnt acces this array, getting its elements in the for
     loop had to be reason for the segmentation fault.

     => looking at the code, notice that obj3 just is a pointer to an
     unintialised Test object, so deleted line 54

-> put break point in main::line 65 and 67
   - at line 56 got error " double free...". noting that we are calling delete
   on obj1 which is just a pointer to a static element in static array, deleted
   line 55 and 57.

*/
