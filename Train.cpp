#include "Train.h"
#include <iomanip>
#include <string>

Train::Train(std :: string n , std :: string t , std :: string o)
{
    no = n;
    to = t;
    over = o;
}
std :: string Train :: get_no()
{
  return no;
}
std :: string Train :: get_to()
{
    return to;
}
std :: string Train :: get_over()
{
    return over;
}
Train::~Train()
{
    std :: cout << "Train " << no << " to " << to << " Hbf deleted\n";
}
