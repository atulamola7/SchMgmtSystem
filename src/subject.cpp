#include "subject.h"
using namespace std;

Subject::Subject()
{
}

Subject::~Subject()
{
}

ostream& operator<<(ostream& os, const Subject* s)
{
  os << "Subject: " << s->m_name;
  return os;
}

ostream& operator<<(ostream& os, const Subject& s)
{
  os << "Subject: " << s.m_name;
  return os;
}

istream& operator>>(istream& is, Subject* s)
{
  is >> s->m_name;
  return is;
}

istream& operator>>(istream& is, Subject& s)
{
  is >> s.m_name;
  return is;
}
