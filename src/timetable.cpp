#include "timetable.h"

using namespace std;


TimeTable::TimeTable()
{
}

TimeTable::~TimeTable()
{
}

ostream& operator<<(ostream& os, const TimeTable*)
{
  return os;
}

ostream& operator<<(ostream& os, const TimeTable&)
{
  return os;
}

istream& operator>>(istream& is, TimeTable*)
{
  return is;
}

istream& operator>>(istream& is, TimeTable&)
{
  return is;
}
