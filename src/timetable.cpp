#include "../include/entities/timetable.h"

using namespace std;


TimeTable::TimeTable()
{
  _Section = NULL;
}

TimeTable::~TimeTable()
{
}

int TimeTable::addAttrs(const vector<pair<string, string> >& attrs)
{
	for(int i = 0; i < attrs.size(); i++)
	{
		if(attrs[i].first == "id") m_id = attrs[i].second;
	}

	return 0;
}

ostream& operator<<(ostream& os, const TimeTable* t)
{
  os << t->m_id;
  return os;
}

ostream& operator<<(ostream& os, const TimeTable& t)
{
  os << t.m_id;
  return os;
}

istream& operator>>(istream& is, TimeTable* t)
{
  is >> t->m_id;
  return is;
}

istream& operator>>(istream& is, TimeTable& t)
{
  is >> t.m_id;
  return is;
}
