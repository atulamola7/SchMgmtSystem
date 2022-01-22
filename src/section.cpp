#include "../include/entities/section.h"
using namespace std;

Section::Section()
{
  _TimeTable = NULL;
  m_maxOccupancy = 0;
  m_roomNo = 0;
  m_name = "Anonymous";
}

Section::~Section()
{
}

int Section::addAttrs(const vector<pair<string, string> >& attrs)
{
	for(int i = 0; i < attrs.size(); i++)
	{
		if(attrs[i].first == "name")			   m_name = attrs[i].second;
		else if(attrs[i].first == "max_occupancy") m_maxOccupancy = atol(attrs[i].second.c_str());
		else if(attrs[i].first == "room_no")	   m_roomNo = atol(attrs[i].second.c_str());
	}

	return 0;
}

ostream& operator<<(ostream& os, const Section* s)
{
  os << "Section: " << s->m_name << ' ' << s->m_maxOccupancy << ' ' << s->m_roomNo;
  return os;
}

ostream& operator<<(ostream& os, const Section& s)
{
  os << "Section: " << s.m_name << ' ' << s.m_maxOccupancy << ' ' << s.m_roomNo;
  return os;
}

istream& operator>>(istream& is, Section* s)
{
  is >> s->m_name >> s->m_maxOccupancy >> s->m_roomNo;
  return is;
}

istream& operator>>(istream& is, Section& s)
{
  is >> s.m_name >> s.m_maxOccupancy >> s.m_roomNo;
  return is;
}
