/*
    CH08-320143
    fraction.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de


*/

#include "fraction.h"
#include <cstdlib> //atoi

Fraction::Fraction()
{
}
Fraction::Fraction(int a,int b) throw(string*)
{
    if(b == 0)
        throw new string("Invalid data or logical error");
    p  = a;
    q = b;
}
Fraction::Fraction(string &fraction) throw(string*)
{

    int i;
    int sign = 1;
    size_t found = fraction.find('/');
    if (found == string::npos)
        throw new string("Invalid data or logical error");
    fraction.erase(found,1); //Remove '/'
    //Look for sign indicators
    if(fraction[0] == '+' || fraction[0] == '-') //if numerator has sign
    {

        if(fraction[0] == '-')
            sign = -1;//Save sign
        fraction.erase(0,1);//Remove numerator's sign
        found--;
    }
    if(fraction[found] == '+' || fraction[found] == '-') //if den has sign
    {
        if(fraction[found] == '-')
        {
            sign*=-1;//Change sign
        }
        fraction.erase(found,1);//Remove sign
    }
    //(If input was valid, only integers must be left now)

    int len = fraction.length();

    for (i = 0 ; i < len ; i++ )
        if(!isdigit(fraction[i]) && (fraction[i] != '+' || fraction[i] != '-'))
            throw new string("Invalid data or logical error");
    string buf = fraction.substr(0,found);//[0,found] = num
    p = atoi(buf.c_str());
    p*=sign;
    buf = fraction.substr(found,fraction.size());//[found,n] = den
    q = atoi(buf.c_str());
}
Fraction::Fraction(Fraction& A)
{
    this->p = A.p;
    this->q =A.q;
}
Fraction::~Fraction()
{
}

Fraction& operator+(const Fraction &A,const Fraction &B)
{
    Fraction *Res = new Fraction;
    Res->p = A.p*B.q + B.p*A.q;
    Res->q = A.q * B.q;
    return *Res;
}
Fraction& operator-(const Fraction &A,const Fraction &B)
{
    Fraction *Res = new Fraction;
    Res->p = A.p*B.q - B.p*A.q;
    Res->q = A.q * B.q;
    return *Res;
}
Fraction& operator/(const Fraction &A,const Fraction &B)
{
    Fraction *Res = new Fraction;
    Res->p = A.p * B.q;
    Res->q = A.q * B.p;
    return *Res;
}
Fraction& operator*(const Fraction &A,const Fraction &B)
{
    Fraction *Res = new Fraction;
    Res->p = A.p * B.p;
    Res->q = A.q *B.q ;
    return *Res;
}

Fraction& Fraction::operator=(const Fraction &A)
{
    this->p = A.p;
    this->q = A.q;
    return *this;
}

bool operator<(const Fraction &A,const Fraction &B)
{

    return A.p*B.q < A.q*B.p;
}
bool operator<=(const Fraction &A,const Fraction &B)
{
    return A < B || A == B;
}
bool operator>(const Fraction &A,const Fraction &B)
{
    return B < A;
}
bool operator>=(const Fraction &A,const Fraction &B)
{
    return A > B || A == B;
}
bool operator==(const Fraction &A,const Fraction &B)
{
    return !(A > B) && !(A < B);
}
bool operator!=(const Fraction &A,const Fraction &B)
{
    return (A > B) ^ (A < B);
}

ostream& operator<<(ostream & out,const Fraction &A)
{
    out << A.p << "/" << A.q;
    return out;
}
istream& operator>>(istream & in, Fraction &A)
{

    string input;
    in>> input;

    try
    {
        A = Fraction(input); //use
    }
    catch(string *)
    {
        throw;
    }
    return in;
}
