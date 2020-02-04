#include "Time.h"
#include <iomanip>
#include <string>

Time::Time(int t )
{
    if (t<0) t = 0;
    minuteOfDay = t%(24*60);
}
Time :: Time (int h , int m)
{
    if (h < 0 || h > 12 || m < 0 || m > 60) h = m = 0;
    minuteOfDay = h*60 + m;
}
void Time :: set_time (int h , int m)
{
    if (h < 0 || h > 12 || m < 0 || m > 60) h = m = 0;
    minuteOfDay = h*60 + m;
}
int Time :: get_hour ()
{
    return minuteOfDay/60;
}
int Time :: get_minute()
{
    return minuteOfDay%60;
}
int Time :: get_minuteOfDay()
{
    return minuteOfDay;
}
Time Time :: operator+(int range)
{
    return(Time(minuteOfDay+range));
}
std :: ostream& operator << (std :: ostream& out , Time& t)
{
    int h = t.get_minuteOfDay()/60;
    int m = t.get_minuteOfDay()%60 ;
    if (h/10 == 0) out <<0 ;
    out <<h << ":";
    if (m/10 == 0) out << 0;
    out << m;
    return out;
}
std :: istream& operator >> (std :: istream& in , Time& t)
{
    char colon;
    int h ,m;
    in >> h >> colon >> m ;
    t.set_time(h,m);
    return in;
}
Time::~Time()
{
    //dtor
}
