#include "stringEx.h"
using namespace std;

string StringEx::replaceAll(string str, const string& toBeReplaced, const string& replaceWith)
{
  string ret;
  int idx = 0;
  while((idx = str.find(toBeReplaced)) != string::npos)
  {
    ret += str.substr(0, idx);
    ret += replaceWith;
    str = str.substr(idx + toBeReplaced.size());
  }
  ret += str;
  return ret;
}
