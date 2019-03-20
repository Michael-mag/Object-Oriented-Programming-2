/*
    CH08-320143
    a4.4
    testAccess.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

*/

#include <iostream>
#include "Access.h"

using namespace std;

int main(void)
{
    unsigned int access_code;
    string prompt = "Enter Acces Code:";
    string success = "Success. Door opened!";
    string failure = "Wrong! Door not Open.";
    //1
    Access Employees;

    //2 Activate
    Employees.activate(1234);
    Employees.activate(9999);
    Employees.activate(9876);

    do//5
    {
        //3 ask for acces code
        cout<<prompt<<endl;
        cin >> access_code;
        //4 tell the user whether the door opened successfully
        cout << (Employees.isactive(access_code) ? success : failure) <<endl;
    }
    while(! Employees.isactive(access_code));  //5

    //6 Deactivate the code that worked and 9999 , 1111

    Employees.deactivate(access_code);
    Employees.deactivate(9999);
    Employees.activate(1111);

    //Repeat Steps 3 and 4

    do //5
    {
        //3 ask for acces code
        cout<<prompt<<endl;
        cin >> access_code;
        //4 tell the user whether the door opened successfully
        cout << (Employees.isactive(access_code) ? success : failure) <<endl;
    }
    while(! Employees.isactive(access_code));  //5

    return 0;
}
