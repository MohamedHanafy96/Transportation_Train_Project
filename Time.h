#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time
{
    public:
        Time(int t = 0);
        Time(int h , int m);
        virtual ~Time();
        void set_time(int h , int m);
         int get_hour();
         int get_minute();
         int get_minuteOfDay();
        Time operator+ ( int range);
    protected:

    private:
         int minuteOfDay;
};
std :: ostream& operator << (std :: ostream& out , Time& t);
std :: istream& operator >> (std :: istream& out , Time& t);
#endif // TIME_H
