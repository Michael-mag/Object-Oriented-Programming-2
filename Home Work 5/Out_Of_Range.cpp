/*
    CH08-320143
    a5_p1.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

int main()
{
    vector<int> my_vector;
    int i;

    for( i = 0; i < 20; i++)
    {
        //Store the number 8 in the vector 20 times
        my_vector.insert(my_vector.begin(),8);//my_vector[i] = 8, i elem [0,20)
    }
    try
    {
        my_vector.at(21); // Try accesing invalid idx, exception is thrown
    }
    catch(out_of_range error)
    {
        cerr<<endl<<endl<<error.what()<<endl;//Disp error that occured
    }
    return 0;
}
