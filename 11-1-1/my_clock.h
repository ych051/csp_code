#ifndef __MY_CLOCK_H__
#define __MY_CLOCK_H__
#include <iostream>
class MyClock {
    public:
        void Tick(int seconds = 1);
        bool SetTime(int hour, int minute, int second);
        int hour() const;
        int minute() const;
        int second() const;
    private:
        int _hour = 0, _min = 0, _sec = 0;
};
std::ostream& operator<<(std::ostream& out, const MyClock& c); 
std::istream& operator>>(std::istream& in, MyClock& c);
#endif