#include "../include/entities/building.h"
#include "../include/utils/stringEx.h"
using namespace std;

Building::Building()
{
  m_buildingArea = 0;
  m_name = "Anonymous";
}

Building::~Building()
{
}

int Building::addAttrs(const vector<pair<string, string> >& attrs)
{
	for(int i = 0; i < attrs.size(); i++)
	{
		if(attrs[i].first == "name") m_name = StringEx::replaceAll(attrs[i].second, "_", " ");
		else if(attrs[i].first == "area") m_buildingArea = atof(attrs[i].second.c_str());
		else if(attrs[i].first == "levels")
		{
			vector<string> levels = StringEx::split(attrs[i].second, ",");
			m_allLevels = levels;
		}
	}
	return 0;
}

ostream& operator<<(ostream& os, const Building* b)
{
  os << "Building: " << b->m_name << ':' << b->m_buildingArea << " {";
  for(int i = 0; i < b->m_allLevels.size(); i++)
	  os << b->m_allLevels[i] << (i < b->m_allLevels.size() - 1 ? ";" : "");
  os << "} "; 
  return os;
}

ostream& operator<<(ostream& os, const Building& b)
{
  os << "Building: " << b.m_name << ':' << b.m_buildingArea << " {";
  for(int i = 0; i < b.m_allLevels.size(); i++)
	  os << b.m_allLevels[i] << (i < b.m_allLevels.size() - 1 ? ";" : "");
  os << "} "; 
  return os;
}

istream& operator>>(istream& is, Building* b)
{
  is >> b->m_name;
  return is;
}

istream& operator>>(istream& is, Building& b)
{
  is >> b.m_name;
  return is;
}
