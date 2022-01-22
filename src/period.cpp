#include "../include/entities/period.h"
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

int Period::addAttrs(const vector<pair<string, string> >& attrs)
{
	for(int i = 0; i < attrs.size(); i++)
	{
		if(attrs[i].first == "start_time") m_startTime = attrs[i].second;
		else if(attrs[i].first == "end_time")   m_endTime = attrs[i].second;
	}

	return 0;
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
