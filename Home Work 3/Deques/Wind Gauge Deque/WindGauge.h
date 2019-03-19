/*
    CH08-320143
    a3_p5.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
*/
#include <deque>

class WindGauge
{
public:
    WindGauge(int t = 12);
    void currentWindSpeed(int v);
    int highest() const;
    int lowest() const;
    int average() const;
private:
    std::deque<int> speed;
    int period;
};
