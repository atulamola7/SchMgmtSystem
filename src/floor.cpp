#include "../include/entities/floor.h"
#include "../include/utils/stringEx.h"
using namespace std;

Floor::Floor()
{
  m_name = "Anonymous";
}

Floor::~Floor()
{
}

int Floor::addAttrs(const vector<pair<string, string> >& attrs)
{
	for(int i = 0; i < attrs.size(); i++)
	{
		if(attrs[i].first == "name") m_name = StringEx::replaceAll(attrs[i].second, "_", " ");
	}

	return 0;
}


ostream& operator<<(ostream& os, const Floor* f)
{
  os << "Floor: " << f->m_name;
  return os;
}

ostream& operator<<(ostream& os, const Floor& f)
{
  os << "Floor: " << f.m_name;
  return os;
}

istream& operator>>(istream& is, Floor* f)
{
  is >> f->m_name;
  return is;
}

istream& operator>>(istream& is, Floor& f)
{
  is >> f.m_name;
  return is;
}
