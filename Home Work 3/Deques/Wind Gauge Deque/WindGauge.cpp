/*
    CH08-320143
    a3_p5.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
*/
#include <numeric>
#include <algorithm>
#include <deque>
#include "WindGauge.h"

using namespace std;

WindGauge::WindGauge(int t) :period(t) {}

void WindGauge::currentWindSpeed(int v)
{
    int n = speed.size() ;
    if(n == period)
    {
        speed.pop_back(); //discard old
    }
    speed.push_front(v); //Add new
}

int WindGauge::highest() const
{
    return *max_element(speed.begin(),speed.end());//Max in deque
}

int WindGauge::lowest() const
{
    return *min_element(speed.begin(),speed.end()); //Min in deque
}
int WindGauge::average() const
{
    int sum = accumulate(speed.begin(),speed.end(),0); //Sum of elements
    int n = speed.size();//Number of elements
    return sum/n;
}
