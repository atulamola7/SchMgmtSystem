#include "student.h"
using namespace std;

Student::Student()
{
  _Class = NULL;
  m_avgPercent = 0.0f;
}

Student::~Student()
{
  _Class = NULL;
  m_avgPercent = 0.0f;
}

ostream& operator<<(ostream& os, const Student* s)
{
  os << "Student: " << s->m_name;
  return os;
}

ostream& operator<<(ostream& os, const Student& s)
{
  os << "Student: " << s.m_name;
  return os;
}

istream& operator>>(istream& is, Student* s)
{
  is >> s->m_name;
  return is;
}

istream& operator>>(istream& is, Student& s)
{
  is >> s.m_name;
  return is;
}
