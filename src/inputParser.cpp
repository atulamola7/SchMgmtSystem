#include "inputParser.h"
using namespace std;

InputParser::InputParser()
{
}

InputParser::~InputParser()
{
}

//int InputParser::lastInterpret(Function& fn, vector<pair<Entity, string> >& info, std::vector<std::pair<Entity, std::string> >& condition)
int InputParser::lastInterpret(Function& fn, vector<pair<string, string> >& info, vector<pair<string, string> >& condition)
{
  if(m_parsedStrings.empty())
    return -1;

  if(m_parsedStrings[0] == "ADD")
    fn = ADD;
  else if(m_parsedStrings[0] == "FIND")
    fn = FIND;
  else if(m_parsedStrings[0] == "LINK")
    fn = LINK;
  else if(m_parsedStrings[0] == "DELETE")
    fn = DELETE;
  else if(m_parsedStrings[0] == "PRINT")
    fn = PRINT;
  else
  {
    cout << "ERROR: Unrecognized function '" << m_parsedStrings[0] << "'." << endl;
    return -1;
  }

  int parsedStrIdx = 0;
  for(parsedStrIdx = 1; parsedStrIdx < m_parsedStrings.size() && m_parsedStrings[parsedStrIdx] != "for"; parsedStrIdx++)
  {
    int kvSeparator = m_parsedStrings[parsedStrIdx].find("=");
    if(kvSeparator == string::npos)
      continue;

    const string& str = m_parsedStrings[parsedStrIdx];
    info.push_back(make_pair(str.substr(0,kvSeparator), str.substr(kvSeparator+1)));
  }

  for(; parsedStrIdx < m_parsedStrings.size(); parsedStrIdx++)
  {
    int kvSeparator = m_parsedStrings[parsedStrIdx].find("=");
    if(kvSeparator == string::npos)
      continue;

    const string& str = m_parsedStrings[parsedStrIdx];
    condition.push_back(make_pair(str.substr(0,kvSeparator), str.substr(kvSeparator+1)));
  }

  return 0;
}

ostream& operator<<(ostream& os, const InputParser* i)
{
  os << "Parsed: ";
  for(int it = 0; it < i->m_parsedStrings.size(); it++)
    os << i->m_parsedStrings[it] << (it < i->m_parsedStrings.size()-1 ? ";" : "");
  return os;
}

ostream& operator<<(ostream& os, const InputParser& i)
{
  os << "Parsed: ";
  for(int it = 0; it < i.m_parsedStrings.size(); it++)
    os << i.m_parsedStrings[it] << (it < i.m_parsedStrings.size()-1 ? ";" : "");
  return os;
}

istream& operator>>(istream& is, InputParser* i)
{
  string data;
  while(is >> data)
  {
    i->m_parsedStrings.push_back(data);
  }
  return is;
}

istream& operator>>(istream& is, InputParser& i)
{
  string data;
  while(is >> data)
  {
    i.m_parsedStrings.push_back(data);
  }
  return is;
}
