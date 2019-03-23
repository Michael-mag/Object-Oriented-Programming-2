
/*
    CH08-320143
    debug1.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

EXPLAMATION AT THE BOTTOM
*/

#include <iostream>
using namespace std;

int sum(int a[], int nr) {
	int s=0;
	for(int i=0; i<nr; i++)//break
		s+=a[i];
	return s;
}

unsigned int difference(unsigned int a, unsigned int b) {
	if (a < b)
		return b-a;
	else
		return a-b;

}

int main() {
	int n;
	cout << "n=";
	cin >> n;
	int v[n];
	cout << "Enter values for the array" << endl;
	for(int i=0; i<n; i++)
		cin >> v[i];
	int result = sum(v, n);
	cout << "Result=" << result << endl;//break
	int x, y;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;//break
	cout << "Difference=" << difference(x, y) << endl;
	return 0;
}

/*********************EXPLAMATION*****************************
-First put break points at line 26 and 33 to make sure input was correct

-Add break in line 7 and in function difference()

-Use print to check each individual var:

    _LINE 7_
*at line 7, was trying to to acces element n of an array with n elements, but
this is accesing some memory outside the array since max_idx of array with n
elements is n-1. so changed stoping criteria of for_loop to i < nr

	_LINE 13_
-at line 16, I called print a , print b and the correct results were produced

-the commands print a -b and print b - a resulted in one of the results being
correct whilst the other was a large number. so in the end if a < b , for
 unsigned int variables, result [a -b] = x is also an unsigned int. since
 [a-b] < 0, the sign bit is treated as a normal bit, thus x will be a large int
 so the comparison always will be false : and according to the function a - b is returned  returning x the incorect answer.

to solve this, modified line 12 to a more direct comparison that does not use
 subtraction


*/
