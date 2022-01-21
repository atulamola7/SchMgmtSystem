#include "inputParser.h"
#include "entityDatabase.h"
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

  fn = EntityDataBase::getFunctionFromStr(m_parsedStrings[0]);
  if(fn == UNDEF)
  {
    cout << "ERROR: Unrecognized function '" << m_parsedStrings[0] << "'." << endl;
    return -1;
  }

  vector<pair<string, string> >* dataHolderPtr = &info;

  int parsedStrIdx = 0;
  for(parsedStrIdx = 1; parsedStrIdx < m_parsedStrings.size(); parsedStrIdx++)
  {
    if(m_parsedStrings[parsedStrIdx] == "for")
      dataHolderPtr = &condition;

    const string& str = m_parsedStrings[parsedStrIdx];
    int kvSeparator = str.find("=");
    if(kvSeparator == string::npos)
      dataHolderPtr->push_back(make_pair("", str));
    else
      dataHolderPtr->push_back(make_pair(str.substr(0,kvSeparator), str.substr(kvSeparator+1)));
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
