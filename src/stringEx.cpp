#include "../include/utils/stringEx.h"
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

vector<string> StringEx::split(string str, const string& delimiter)
{
	vector<string> ret;

	int idx = 0;
	while((idx = str.find(delimiter)) != string::npos)
	{
		ret.push_back(str.substr(0, idx));
		str = str.substr(idx + delimiter.size());
	}
	ret.push_back(str);

	return ret;
}
