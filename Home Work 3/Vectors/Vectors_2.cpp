
/*
    CH08-320143
    a3_p2.cpp
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
    getline(cin,input[i]);//string must not contain white space
    i++;
  }while(input[i-1] != "END");

  i--;
  //insert inside the vector
  for(j = 0; j<i; j++){
    string_vector.push_back(input[j]);
  }

  //Original Input
  cout<<endl<<"Original Input : "<<endl;
  for(j=0;j<i;j++){
    cout<<string_vector[j]<<" ";
  }
  //check if possible to swap string 2 with string 5 and swap them
  if(i>=4){
    swap(string_vector[1],string_vector[4]);//indexing starts at 0
  }else if(i>1 && i<4){
    cout<<endl<<"No 5th position element to swap with."<<endl;
  }else{
    cout<<endl<<"Vector contains less than 2 strings."<<endl;
  }

  //replace the last string with "???"
  string_vector.back()="???";

  //print using Index Operator
  cout<<endl<<endl<<"WITH THE LAST STRING REPLACED : "<<endl;
  cout<<endl<<"Using Index Operator : "<<endl;
  cout<<string_vector[0];//print the first element
  for(j=1;j<i;j++){
    cout<<","<<string_vector[j];
  }
  cout<<endl;

  //print using Iterator
  cout<<endl<<"Using Iterator : "<<endl;
  vector<string>::const_iterator iterate = string_vector.begin();//declaring iterator for the vector
  cout<<endl<<*iterate; //print the first string
  for(iterate++; iterate != string_vector.end();iterate++){
    cout<<";"<<*iterate;
  }
  cout<<endl;

  //print the strings in reverse order
  cout<<endl<<"Printing in reverse Order : "<<endl;
  for(iterate--; iterate!=string_vector.begin()-1;iterate--){
    cout<<*iterate<<" ";
  }
  cout<<endl;

  return 0;
}
