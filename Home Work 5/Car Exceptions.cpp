/*
    CH08-320143
    a5_p2.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de


*/
#include <iostream>
#include <exception>

using namespace std;

class Motor
{
private:

public:
    Motor()
    {
        throw "This motor has problems";
    }
    ~Motor(){}
};

class Car
{
private:
    Motor* motor_obj;

public:
    Car()
    {
        try
        {
            motor_obj = new Motor();
        }
        catch (const char* msg)
        {
            throw;
        }
    }

    ~Car()
    {
        delete motor_obj;
    }
};

class Garage
{
private:
    Car* car_obj;

public:
    Garage()
    {
        try
        {
            car_obj = new Car();
        }
        catch(const char* msg)
        {
            throw "The car in this garage has problems with the motor";
        }
    }
    ~Garage()
    {
        delete car_obj;
    }
};


int main()
{

    try
    {
        Garage AUDI;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }

    return 0;
}
