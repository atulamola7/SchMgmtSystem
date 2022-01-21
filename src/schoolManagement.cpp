#include "schoolManagement.h"
#include <sstream>
using namespace std;

#define MAJOR_VERSION 0
#define MINOR_VERSION 1
#define REVISION 0

void PrintSMSVersion()
{
  cout << "School Management System - " << MAJOR_VERSION << '.' << 
                   MINOR_VERSION << '.' << REVISION << endl << endl;
  cout << "You are using 'School Management System Backend Application(system app)." << endl;
}

#undef MAJOR_VERSION
#undef MINOR_VERSION

SchoolManager::SchoolManager()
{
}

SchoolManager::~SchoolManager()
{
}

int SchoolManager::init()
{
  //TODO In this step, it will read all the data files containing all info
  return 0;
}

int SchoolManager::run()
{
  //TODO In this function, an ever running loop is entered, which will take queries
  // and do the needful
  string data;
  cout << "#> " << flush;
  while(getline(cin, data))
  {
    if(data.substr(0,2) == "\\q")
      break;

    stringstream ss;
    ss << data;

    InputParser ip;
    ss >> ip;

    Function fn = UNDEF;
    vector<pair<string,string> > info, cond;
    ip.lastInterpret(fn, info, cond);

#if 0
    cout << "Interpreted as: " << fn << endl;
    cout << "Info: " << endl;
    for(int i = 0; i < info.size(); i++)
      cout << "\t" << info[i].first << ' ' << info[i].second << endl;

    cout << "Cond: " << endl;
    for(int i = 0; i < cond.size(); i++)
      cout << "\t" << cond[i].first << ' ' << cond[i].second << endl;
#endif

    cout << "#> " << flush;
  }

  if(data.empty())
    cout << "\\q" << endl;

  m_eDB.printEntityDetails();

  return 0;
}

// THIS main is hidden inside the cpp file;
// Mainly because main class is SchoolManager 
// and all the functionalities start from the 
// manager
int main()
{
  PrintSMSVersion();
  SchoolManager schManager;
  if(schManager.init() != 0)
  {
    cout << "School Management System: Initialization failed!" << endl;
    return -1;
  }

  return schManager.run();
}
