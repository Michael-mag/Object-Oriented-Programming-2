/*
    CH08-320143
    a4.4
    Access.h
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de


*/

#ifndef ACCESS_H
#define ACCESS_H

#include <set> // No repitition of keys and fast searching
class Access
{
public:
    void activate(unsigned int );
    void deactivate(unsigned int);
    bool isactive(unsigned int) const;
private:
    std::set<unsigned int> Keys;

};
#endif
