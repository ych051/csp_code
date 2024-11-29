#include "calendar.h"

MyCalendar::MyCalendar(): _year(0), _month(1), _day(1) {}
MyCalendar::MyCalendar(int year, int month, int day) {
    if(!SetDate(year, month, day)) {_year = 0; _month = 1; _day = 1;}
}

bool MyCalendar::NextDay(int n){
    for (int i = 0; i < abs(n); ++i){
        if (n > 0) {
            _day++;
            int days_in_month;
            if (_month == 2) {
                if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)) {
                    days_in_month = 29;
                } else {
                    days_in_month = 28;
                }
            } else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
                days_in_month = 30;
            } else {
                days_in_month = 31;
            }

            if (_day > days_in_month) {
                _day = 1;
                ++_month;
                if (_month > 12) {
                    _month = 1;
                    ++_year;
                }
            }
        }
        else {
            _day--;
            if (_day < 1) {
                --_month;
                if (_month < 1) {
                    _month = 12;
                    if (_year > 0) {
                        --_year;
                    } else {
                        
                        _month=1;
                        _day = 1;
                        return false;
                    }
                }
                if (_month == 2) {
                    if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)) {
                        _day = 29;
                    } else {
                        _day = 28;
                    }
                } else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
                    _day = 30;
                } else {
                    _day = 31;
                }
            }
        }
    }
    return true;
}

bool MyCalendar::SetDate(int year, int month, int day){
    if(year>=0 && year<=9999 && month>=1 && month<=12){
        int day_in_month;
        if(month==2){
            if((year%4==0 && year%100!=0)||(year%400==0)) day_in_month=29;
            else day_in_month=28;
        }
        else{
            if(month<=7){
                if(month%2==0) day_in_month=30;
                else day_in_month=31;
            }
            else{
                if(month%2==0) day_in_month=31;
                else day_in_month=30;
            }
        }
        if(day>=1 && day<=day_in_month){
            _year=year;
            _month=month;
            _day=day;
            return true;
        }
        
    }
    return false;
}

int MyCalendar::year() const{return _year;}
int MyCalendar::month() const{return _month;}
int MyCalendar::day() const {return _day;}

int MyCalendar::GetDaysInYear(int year){
    if((year%4==0 && year%100!=0)||(year%400==0)) return 366;
    else return 365;
}
int MyCalendar::ComputeDaysFromYearStart(int year, int month, int day){
    return 0;
}

std::ostream& operator<<(std::ostream& out, const MyCalendar& c){
    out << c.year() << '.' << c.month() << '.' << c.day() << '\n';
    return out;
}
std::istream& operator>>(std::istream& in, MyCalendar& c){
    int year, month, day;
    char colon1, colon2;
    in >> year >> colon1 >> month >> colon2 >> day;
    if(!c.SetDate(year, month, day)){
        std::cout << "Invalid date: " << year << '.' << month << '.' << day << '\n';
    } 
    return in;
}