#include "../include/entities/principal.h"
using namespace std;

Principal::Principal()
{
}

Principal::~Principal()
{
}

ostream& operator<<(ostream& os, const Principal* p)
{
  return os;
}

ostream& operator<<(ostream& os, const Principal& p)
{
  return os;
}

istream& operator>>(istream& is, Principal* p)
{
  return is;
}

istream& operator>>(istream& is, Principal& p)
{
  return is;
}
