#include "teacher.h"
using namespace std;

Teacher::Teacher()
{
  _Subject = NULL;
  _TeacherTT = NULL;
  m_name = "Anonymous";
}

Teacher::~Teacher()
{
  _Subject = NULL;
  _TeacherTT = NULL;
}

ostream& operator<<(ostream& os, const Teacher* t)
{
  os << "Teacher: " << t->m_name;
  return os;
}

ostream& operator<<(ostream& os, const Teacher& t)
{
  os << "Teacher: " << t.m_name;
  return os;
}

istream& operator>>(istream& is, Teacher* t)
{
  is >> t->m_name;
  return is;
}

istream& operator>>(istream& is, Teacher& t)
{
  is >> t.m_name;
  return is;
}
