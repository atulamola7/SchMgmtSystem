#include "class.h"
using namespace std;

Class::Class()
{
  m_name = "Anonymous";
}

Class::~Class()
{
}

ostream& operator<<(ostream& os, const Class* c)
{
  os << "Class: " << c->m_name;
  return os;
}

ostream& operator<<(ostream& os, const Class& c)
{
  os << "Class: " << c.m_name;
  return os;
}

istream& operator>>(istream& is, Class* c)
{
  is >> c->m_name;
  return is;
}

istream& operator>>(istream& is, Class& c)
{
  is >> c.m_name;
  return is;
}
