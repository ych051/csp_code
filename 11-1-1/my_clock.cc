#include "my_clock.h"

std::ostream& operator<<(std::ostream& out, const MyClock& c){
    out << c.hour() << ':' << c.minute() << ':' << c.second() << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, MyClock& c){
    int hour, min, sec;
    char colon1, colon2;
    in >> hour >> colon1 >> min >> colon2 >> sec;
    if(!c.SetTime(hour, min, sec)){
        std::cout << "Invalid time: " << hour << ':' << min << ':' << sec << '\n';
    }
    return in;
}

void MyClock::Tick(int seconds){
    _sec += seconds;
    int total_seconds = _hour * 3600 + _min * 60 + _sec;
    if (total_seconds < 0) {
        total_seconds = (24 * 3600 + total_seconds % (24 * 3600)) % (24 * 3600);
    }
    else if(total_seconds>24*3600) total_seconds-=(24*3600);
    _hour = total_seconds / 3600;
    _min = (total_seconds % 3600) / 60;
    _sec = total_seconds % 60;
}
bool MyClock::SetTime(int hour, int minute, int second){
    if(hour>=24 || hour<0 || minute > 60 || minute < 0 || second > 60 || second < 0) return false;
    _hour=hour;
    _min=minute;
    _sec=second;
    return true;
}

int MyClock::hour() const{
    return _hour;
}
int MyClock::minute() const{
    return _min;
}
int MyClock::second() const{
    return _sec;
}