#include "building.h"
using namespace std;

Building::Building()
{
  m_buildingArea = 0;
  m_name = "Anonymous";
}

Building::~Building()
{
}

ostream& operator<<(ostream& os, const Building* b)
{
  os << "Building: " << b->m_name;
  return os;
}

ostream& operator<<(ostream& os, const Building& b)
{
  os << "Building: " << b.m_name;
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
