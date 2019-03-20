/*
    CH08-320143
    a4_p3.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de


*/
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#define RANGES A.begin(),A.end(),B.begin(),B.end()

using namespace std;

template <class T>
void Print(T A){
	for(int elA : A)
        cout<<elA<<" ";
        cout<<endl<<endl;
}

int main()
{
    //1. Create set A and multiset B taht both take integers
    set<int> A;
    multiset<int> B;
    int in;

    //read from stdin and insert
    while(true)
    {
        cin>>in;
        if(in <  0)
        {
            break;
        }
        A.insert(in);
        B.insert(in);
    }

    //5.1 Print A
    Print(A);

    //5.2 Print B
    Print(B);

    //7 Remove all elements with value = 5
    // No duplicates in a set,thus just find the occurence and erase
    A.erase(A.find(5));

    // Duplication of entries in multiset, thus scan through the entire set and
		//erase the occurences
    while(B.find(5) != B.end())
    {
        B.erase(B.find(5));
    }

    // 8.1 Print A
    Print(A);

    //8.2 Print B
    Print(B);

    //Add 14 and 198 to A
    A.insert({14,198});

    //10 A union B
    multiset<int> AuB;

    set_union(RANGES,inserter(AuB,AuB.begin()));

    Print(AuB);

    //11 A intersection B
    set<int> AnB;

    set_intersection(RANGES,inserter(AnB,AnB.begin()));

    Print(AnB);

    //12 A\B
    set<int> A_minus_B; //A - B, minus as  '_'

    set_difference(RANGES,inserter(A_minus_B,A_minus_B.begin()));

    Print(A_minus_B);

    //13 Symetric Difference of A and B
    set<int> sym_diff_AB; //A - B,

   set_symmetric_difference(RANGES,inserter( sym_diff_AB ,sym_diff_AB.begin()));

   Print(sym_diff_AB);

    return 0;
}
