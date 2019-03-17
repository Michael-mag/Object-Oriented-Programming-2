/*
    CH08-320143
    a3_p1.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
*/

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<string> string_vector;
  string input[100];
  int i = 0,j;

  cout<<endl<<"Enter the strings (END to quit) : "<<endl<<endl;

  do{
    cin>>input[i];//string must not contain white space
    i++;
  }while(input[i-1] != "END");

  i--;
  //insert inside the vector
  for(j = 0; j<i; j++){
    string_vector.push_back(input[j]);
  }

  //print using index operator
  cout<<endl<<"Using Index Operator : "<<endl;
  for(j=0;j<i;j++){
    cout<<string_vector[j]<<" ";
  }
  cout<<endl<<endl;

  //print using iterator
  cout<<"Using Iterator : "<<endl;
  vector<string>::const_iterator iterate = string_vector.begin();/* declacring the iterator
  itarete to the vector*/
  cout<<*iterate;//print the first element
  for(iterate++; iterate != string_vector.end(); iterate++){
    cout<<","<<*iterate;
  }
  cout<<endl;
  return 0;
}
