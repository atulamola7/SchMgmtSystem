#include "floor.h"
using namespace std;

Floor::Floor()
{
}

Floor::~Floor()
{
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
