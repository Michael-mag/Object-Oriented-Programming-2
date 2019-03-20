/*
    CH08-320143
    a4.6
    Access.h
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

*/
#ifndef ACCESS_H
#define ACCESS_H

#include <map> //no duplicate
class Access
{
public:
    void activate(unsigned int,unsigned int );
    void deactivate(unsigned int);
    bool isactive(unsigned int,unsigned int) const;
private:
    std::map<unsigned int,unsigned int> Keys;

};
#endif
