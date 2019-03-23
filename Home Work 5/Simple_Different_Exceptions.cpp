/*
    CH08-320143
    a5_2.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
*/

/*
    Problem 5.2 Simple different exceptions (2 points)
    Presence assignment, due by 18:30 h today
    
    Write a program and a function with an integer parameter which can throw four exception types:
    a char, an int, a bool, and your own exception class called OwnException derived from
    exception. If the parameter of the function is 1 then the character ’a’ should be thrown, if it’s 2
    then the integer 12 should be thrown, if it’s 3 then the bool value true should be thrown, and
    in the default case an OwnException with the string ”Default case exception” should be
    thrown. You should overwrite the what() method for the OwnException class by returning
    the string ”OwnException\n”. Call the function in the main function in its four versions and
    catch the corresponding exceptions. In the catch blocks you should print to the standard error
    stream cerr the string ”Caught in main: ” followed by the value of the thrown exception.
    In the case of OwnException print the string returned by the what() method.

*/

#include<bits/stdc++.h>
using namespace std;

class OwnException : public exception {
private:
  string err_msg;
public:
  OwnException(string msg) : err_msg(msg){}
  virtual ~OwnException() throw() {};
  virtual const char *what(){
    return "Own Exception \n";
  }

};

void funct(int parameter){
  switch (parameter)
  {
  case 1:
      throw 'a';
      break;
  case 2:
      throw 12;
      break;
  case 3:
      throw true;
      break;
  default:
      throw OwnException ("Default case exception");
      break;
    }
}

int main(int argc, char const *argv[]) {
  srand((unsigned)time(0));
  int call = rand() % 4+1;

  cout<<endl<<endl;

  try{
    funct(call);
  }

  catch (char a)
  {
      cerr<<"Caught in main: "<<a<<endl;
  }
  catch (int i)
  {
      cerr<<"Caught in main: "<<i<<endl;
  }
  catch (bool T)
  {
      cerr<<"Caught in main: "<<boolalpha<<T<<endl;
  }
  catch (OwnException obj)
  {
      cerr<<"Caught in main: "<<obj.what();
  }

  return 0;
}
