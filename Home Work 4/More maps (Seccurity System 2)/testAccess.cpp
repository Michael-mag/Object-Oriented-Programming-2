/*
    CH08-320143
    a4.6
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
    Employees.activate(1234,1);
    Employees.activate(9999,5);
    Employees.activate(9876,9);


    do //5
    {
        //3 ask for acces code
        Employees.deactivate(9876);
        cout<<prompt<<endl;
        cin >> access_code;
        //4 tell the user whether the door opened successfully
        cout << (Employees.isactive(access_code,5) ? success : failure) <<endl;
    }
    while( !Employees.isactive(access_code,5));  //5

    cout<<endl;
    //6 Deactivate the code that worked and change 9999 to lvl 8
    // ,activat 1111 with lvl 7

    Employees.deactivate(access_code);
    Employees.deactivate(9999);//first deactivate
    Employees.activate(9999,8);//activate with new privilage lvl
    Employees.activate(1111,7);

    //Repeat Steps 3 and 4

    do //9
    {
        //7 ask for acces code
        Employees.deactivate(9999);
        Employees.deactivate(9876);
        Employees.deactivate(1234);
        cout<<prompt<<endl;
        cin >> access_code;
        //8 tell the user whether the door opened successfully
        cout << (Employees.isactive(access_code,7) ? success : failure) <<endl;
    }
    while(! Employees.isactive(access_code,7));  //9

    return 0;
}
