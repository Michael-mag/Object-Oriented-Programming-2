/*
    CH08-320143
    a4_p1.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

    Reversing a vector
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int i;
  vector<int> storage;
  vector<int>::iterator j; //declaring the iterator for the vector

  //fill the vector with integer values from 1-30
  for(i=0;i<30;i++){
    storage.push_back(i);//insert at the end
  }
  //add 5 at the end
  storage.push_back(5);

  //reversing the Vector
  reverse(storage.begin(),storage.end());

  //print the reversed vector using Iterator
  cout<<endl<<endl<<"Output in reverse order : "<<endl;
  for(j=storage.begin();j!=storage.end();j++){
    cout<<*j<<" ";
  }
  cout<<endl<<endl;

  //Replacing all the occurances of 5 by 129
  replace(storage.begin(),storage.end(),5,129);//replaces 5 by 129
  cout<<endl<<endl<<"Output with 5 replaced by 129 : "<<endl;
  for(j=storage.begin();j!=storage.end();j++){
    cout<<*j<<" ";
  }
  cout<<endl<<endl;
  return 0;
}
