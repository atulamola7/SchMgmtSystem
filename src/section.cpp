#include "section.h"
using namespace std;

Section::Section()
{
  _TimeTable = NULL;
  m_maxOccupancy = 0;
  m_roomNo = 0;
}

Section::~Section()
{
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
