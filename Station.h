#ifndef STATION_H
#define STATION_H
#include "Train.h"
#include "Time.h"
#include <iostream>
class Train;
class Time;
class Station
{
    public:
        Station(std :: string name);
        void addDeparture (Time t , int p , Train* train );
        void ShowDeparture (Time t , int range);
        virtual ~Station();

    protected:

    private:
        std :: string station;
        unsigned int platforms;
        Train* schedule[24*60+3][15+3] {};
};

#endif // STATION_H
