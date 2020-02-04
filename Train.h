#ifndef TRAIN_H
#define TRAIN_H
#include <iostream>

class Train
{
    public:
        Train(std :: string n , std :: string t , std :: string o);
        virtual ~Train();
        std :: string get_no();
        std :: string get_to();
        std :: string get_over();
    protected:

    private:
        std :: string no , to , over;
};

#endif // TRAIN_H
