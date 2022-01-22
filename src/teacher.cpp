#include "../include/entities/teacher.h"
#include "../include/utils/stringEx.h"
using namespace std;

Teacher::Teacher()
{
  _Subject = NULL;
  _TeacherTT = NULL;
  m_name = "Anonymous";
  m_tchrId = "0";
}

Teacher::~Teacher()
{
  _Subject = NULL;
  _TeacherTT = NULL;
}

int Teacher::addAttrs(const vector<pair<string, string> >& attrs)
{
  for(int i = 0; i < attrs.size(); i++)
  {
    if(attrs[i].first == "name")    m_name = StringEx::replaceAll(attrs[i].second, "_", " ");
    else if(attrs[i].first == "t_id")  m_tchrId = attrs[i].second;
  }

  return 0;
}

ostream& operator<<(ostream& os, const Teacher* t)
{
  os << "Teacher: " << t->m_name << ':' << t->m_tchrId;
  return os;
}

ostream& operator<<(ostream& os, const Teacher& t)
{
  os << "Teacher: " << t.m_name << ':' << t.m_tchrId;
  return os;
}

istream& operator>>(istream& is, Teacher* t)
{
  is >> t->m_name >> t->m_tchrId;
  return is;
}

istream& operator>>(istream& is, Teacher& t)
{
  is >> t.m_name >> t.m_tchrId;
  return is;
}
