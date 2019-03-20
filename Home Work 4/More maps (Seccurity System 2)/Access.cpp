/*
    CH08-320143
    a4.6
    Access.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

*/

#include <map>
#include "Access.h"

using namespace std;

void Access::activate(unsigned int code,unsigned int level) // Activate code
{
    Keys.insert(pair<unsigned int,unsigned int>(code,level));
}
void Access::deactivate(unsigned int code)//Deactivate code
{
     Keys.erase(code);
}
bool Access::isactive(unsigned int code,unsigned int level) const
{
  return (Keys.find(code)  != Keys.end() )&& (Keys.find(code)->second >= level);
}
