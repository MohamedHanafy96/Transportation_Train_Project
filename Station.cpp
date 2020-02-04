
#include "Station.h"
#include <iomanip>
#include <string>
Station::Station(std :: string name)
{
    station = name;
    platforms = 15;

}
void Station :: addDeparture (Time t, int p, Train* train )
{
    if (p> platforms || p<0) p = 0;
    schedule[t.get_minuteOfDay()][p] = train;
}
void Station :: ShowDeparture (Time t, int range )
{
    int cnt = 0;
    for (int i = t.get_minuteOfDay() ;  ; ++i)
    {
        i = i % (24*60);
        Time tmp (i);
        if (cnt > range) break;
        for (int j = 0 ; j<platforms+1 ; ++j)
        {
            //std :: cout << fixed << setw(40) <<  schedule[i][j]->get_to() ;
            if (schedule[i][j])
            {

                std :: cout << std :: fixed << std :: setw(1 ) << tmp ;
                std :: cout << std :: fixed << std :: setw(7) << schedule[i][j]->get_no() ;
                std :: cout << std :: fixed << std :: setw(50) <<  schedule[i][j]->get_over() ;
                std :: cout << std :: fixed << std :: setw(20) <<  schedule[i][j]->get_to() ;
                std :: cout << std :: fixed << std :: setw(5) <<  j ;
                std :: cout << "\n";
            }
        }
        cnt++;
    }
}
Station::~Station()
{
    for (int i = 0; i<(24*60) ;  ++i)
    {
        for (int j = 0 ; j<platforms+1 ; ++j)
        {
            if (schedule[i][j])
            {
                Time tmp(i);
                std :: cout << tmp << " Platform " << j << ": ";
                schedule[i][j]->~Train();
            }
        }
    }
    std :: cout << "\n";
}

