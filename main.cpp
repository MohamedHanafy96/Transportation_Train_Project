/******************************************************
Aufgabe Nr./Task No.:          H4
Nachname/Last,Family Name:     Hanafy
Vorname/First,Given Name:      Mohamed
Matr.-nr./Matr.-no.:           3060606
Uni-Email:                     mohamed.hanafy@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*******************************************************/
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class Train
{
public:
    Train(string n,  string t,  string o)
    {
        no = n;
        to = t;
        over = o;
    }
    virtual ~Train()
    {
         cout << "Train " << no << " to " << to << " Hbf deleted\n";
    }
    string get_no()
    {
        return no;
    }
    string get_to()
    {
        return to;
    }
    string get_over()
    {
        return over;
    }
private:
     string no, to, over;
};
class Time
{
public:
    Time(int t = 0)
    {
        if (t<0) t = 0;
        minuteOfDay = t % (24 * 60);
    }
    Time(int h, int m)
    {
        if (h < 0 || h > 12 || m < 0 || m > 60) h = m = 0;
        minuteOfDay = h * 60 + m;
    }
    virtual ~Time()
    {

    }
    void set_time(int h, int m)
    {
        if (h < 0 || h > 12 || m < 0 || m > 60) h = m = 0;
        minuteOfDay = h * 60 + m;
    }
    int get_hour()
    {
        return minuteOfDay / 60;
    }
    int get_minute()
    {
        return minuteOfDay % 60;
    }
    int get_minuteOfDay()
    {
        return minuteOfDay;
    }
    Time operator+ (int range)
    {
        return(Time(minuteOfDay + range));
    }
private:
    int minuteOfDay;

};
ostream& operator << ( ostream& out, Time& t)
{
    int h = t.get_minuteOfDay() / 60;
    int m = t.get_minuteOfDay() % 60;
    if (h / 10 == 0) out << 0;
    out << h << ":";
    if (m / 10 == 0) out << 0;
    out << m;
    return out;
}
istream& operator >> ( istream& in, Time& t)
{
    char colon;
    int h, m;
    in >> h >> colon >> m;
    t.set_time(h, m);
    return in;
}

class Station
{
public:
    Station( string name)
    {
        station = name;
        platforms = 15;
    }
    void addDeparture(Time t, int p, Train* train)
    {
        if (p> platforms || p<0) p = 0;
        schedule[t.get_minuteOfDay()][p] = train;
    }
    void ShowDeparture(Time t, int range)
    {
        int cnt = 0;
        for (int i = t.get_minuteOfDay(); ; ++i)
        {
            i = i % (24 * 60);
            Time tmp(i);
            if (cnt > range) break;
            for (int j = 0; j<platforms + 1; ++j)
            {
                if (schedule[i][j])
                {

                    cout << fixed << setw(1) << tmp;
                    cout << fixed << setw(7) << schedule[i][j]->get_no();
                    cout << fixed << setw(50) << schedule[i][j]->get_over();
                    cout << fixed << setw(20) << schedule[i][j]->get_to();
                    cout << fixed << setw(5) << j;
                    cout << "\n";
                }
            }
            cnt++;
        }
    }
    virtual ~Station()
    {
        for (int i = 0; i<(24 * 60); ++i)
        {
            for (int j = 0; j<platforms + 1; ++j)
            {
                if (schedule[i][j] != 0)
                {
                    Time tmp(i);
                    cout << tmp << " Platform " << j << ": ";
                    schedule[i][j]->~Train();
                }
            }
        }
         cout << "\n";
      cout << "Schedule for " << station << " completely deleted.\n";

    }
private:
     string station;
    unsigned int platforms;
    Train* schedule[24 * 60 + 5][15 + 5] {};
};
int maiin()
{
    string sName = "DUISBURG MAIN TRAIN STATION";
    Station duisburg(sName);
    unsigned int choice, range, p;
    string Tno, Tto, Tover;
    Time t, finalT;
    for (int i = 7; i< (24 * 60); i += 20)
    {
        duisburg.addDeparture(Time(i), 9, new Train("S1", "Dortmund Hbf", "Muelheim(Ruhr)Styrum - Muelheim(Ruhr) - Essen"));
    }
    for (int i = 15; i< (24 * 60); i += 20)
    {
        duisburg.addDeparture(Time(i), 5, new Train("S1", "Solingen Hbf", "Duisburg-Schlenk - Duesseldorf Flughafen"));
    }
    for (int i = 35; i< (24 * 60); i += 60)
    {
        duisburg.addDeparture(Time(i), 2, new Train("S2", "Dortmund Hbf", "Oberhausen - Gelsenkirchen - Wanne-Eickel"));
    }
    for (int i = 22; i< (24 * 60); i += 60)
    {
        duisburg.addDeparture(Time(i), 4, new Train("RE1", "Aachen Hbf", "Duesseldorf Flughafen - Duesseldorf - Koeln"));
    }
    for (int i = 24; i< (24 * 60); i += 60)
    {
        duisburg.addDeparture(Time(i), 10, new Train("RE2", "Muenster Hbf", "Muelheim(Ruhr) - Essen - Gelsenkirchen"));
    }
    while (true)
    {
        cout << "0 End\n1 Schedule Train\n2 Show Train\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
        {
            cout << "Time of departure? ";
            cin >> t;
            cout << "Platform? ";
            cin >> p;
            cout << "Train? ";
            cin.ignore();
            getline(cin, Tno);
            cout << "To? ";
            cin.ignore();
            getline(cin, Tto);
            cout << "Over? ";
            cin.ignore();
            getline(cin, Tover);
            Train* tmpTrain = new Train(Tno, Tto, Tover);
            duisburg.addDeparture(t, p, tmpTrain);
            break;
        }
        case 2:
        {
            cout << "Show departures starting at? ";
            cin >> t;
            cout << "For how many next minutes? ";
            cin >> range;
            finalT = t + range;
            cout << sName << "\nDEPARTURES " << t << "  -  " << finalT << "\n====================================\n\n";
            cout << "Time";
            cout << fixed << setw(9) << "Train";
            cout << fixed << setw(25) << "Over";
            cout << fixed << setw(35) << "To";
            cout << fixed << setw(20) << "Platform\n";
            duisburg.ShowDeparture(t, range);
            cout << "\n\n";
            break;
        }
        default:
            return 0;
        }
    }
    return 0;
}
