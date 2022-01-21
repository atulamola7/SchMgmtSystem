#include "student.h"
#include "stringEx.h"
using namespace std;

Student::Student()
{
  _Section = NULL;
  m_avgPercent = 0.0f;
  m_rollNo = "0";
  m_name = "Anonymous";
}

Student::~Student()
{
  _Section = NULL;
  m_avgPercent = 0.0f;
}

int Student::addAttrs(const std::vector<std::pair<std::string, std::string> >& attrs)
{
  for(int i = 0; i < attrs.size(); i++)
  {
    if(attrs[i].first == "name")    m_name = StringEx::replaceAll(attrs[i].second, "_", " ");
    else if(attrs[i].first == "roll_no") m_rollNo = attrs[i].second;
  }

  return 0;
}

ostream& operator<<(ostream& os, const Student* s)
{
  os << "Student: " << s->m_name << ':' << s->m_rollNo;
  return os;
}

ostream& operator<<(ostream& os, const Student& s)
{
  os << "Student: " << s.m_name << ':' << s.m_rollNo;
  return os;
}

istream& operator>>(istream& is, Student* s)
{
  is >> s->m_name >> s->m_rollNo;
  return is;
}

istream& operator>>(istream& is, Student& s)
{
  is >> s.m_name >> s.m_rollNo;
  return is;
}
