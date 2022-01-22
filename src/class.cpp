#include "../include/entities/class.h"
#include "../include/utils/stringEx.h"
using namespace std;

Class::Class()
{
  m_name = "Anonymous";
}

Class::~Class()
{
}

int Class::addAttrs(const vector<pair<string, string> >& attrs)
{
	for(int i = 0; i < attrs.size(); i++)
	{
		if(attrs[i].first == "name") m_name = StringEx::replaceAll(attrs[i].second, "_", " ");
	}
	return 0;
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
