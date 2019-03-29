/*
    CH08-320143
    fraction.h
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de


*/
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction
{
private:
    int p;
    int q;
public:
    Fraction();
    Fraction(int a ,int b) throw(std::string*);
    Fraction(std::string& a) throw(std::string*);
    Fraction(Fraction &A);
    ~Fraction();

    friend Fraction& operator+(const Fraction &A,const Fraction &B);
    friend Fraction& operator-(const Fraction &A,const Fraction &B);
    friend Fraction& operator/(const Fraction &A,const Fraction &B);
    friend Fraction& operator*(const Fraction &A,const Fraction &B);

    Fraction &operator=(const Fraction &A);

    friend bool operator<(const Fraction &A,const Fraction &B);
    friend bool operator<=(const Fraction &A,const Fraction &B);
    friend bool operator>(const Fraction &A,const Fraction &B);
    friend bool operator>=(const Fraction &A,const Fraction &B);
    friend bool operator==(const Fraction &A,const Fraction &B);
    friend bool operator!=(const Fraction &A,const Fraction &B);

    friend std::ostream& operator<<(std::ostream & out,const Fraction &A);
    friend std::istream& operator>>(std::istream & in, Fraction &A);

};

#endif
