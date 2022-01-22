#include "../include/entities/subject.h"
#include "../include/utils/stringEx.h"
using namespace std;

Subject::Subject()
{
  m_name = "Anonymous";
}

Subject::~Subject()
{
}

int Subject::addAttrs(const vector<pair<string, string> >& attrs)
{
	for(int i = 0; i < attrs.size(); i++)
	{
		if(attrs[i].first == "name") m_name = StringEx::replaceAll(attrs[i].second, "_", " ");
	}

	return 0;
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
