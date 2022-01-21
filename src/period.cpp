#include "period.h"
using namespace std;

Period::Period()
{
  _Class = NULL;
  _Teacher = NULL;
  _Subject = NULL;
}

Period::~Period()
{
}

ostream& operator<<(ostream& os, const Period* p)
{
  os << "Period: " << p->m_startTime << " - " << p->m_endTime;
  return os;
}

ostream& operator<<(ostream& os, const Period& p)
{
  os << "Period: " << p.m_startTime << " - " << p.m_endTime;
  return os;
}

istream& operator>>(istream& is, Period* p)
{
  is >> p->m_startTime >> p->m_endTime;
  return is;
}

istream& operator>>(istream& is, Period& p)
{
  is >> p.m_startTime >> p.m_endTime;
  return is;
}
