/*
    CH08-320143
    a4.4
    Access.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

*/

#include <set>
#include "Access.h"

using namespace std;

void Access::activate(unsigned int code ) // Activate code
{
    Keys.insert(code);
}
void Access::deactivate(unsigned int code)//Deactivate code
{
    Keys.erase(code);
}
bool Access::isactive(unsigned int code) const
{
    return Keys.find(code)  != Keys.end();
}
