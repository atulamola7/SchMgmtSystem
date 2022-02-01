#include "../include/manager/schoolManagement.h"
#include <sstream>
using namespace std;

#define MAJOR_VERSION 0
#define MINOR_VERSION 5
#define REVISION 2

void PrintSMSVersion()
{
  cout << "School Management System - " << MAJOR_VERSION << '.' << 
                   MINOR_VERSION << '.' << REVISION << endl;
  cout << "You are using 'School Management System Backend Application'(system app)." << endl << endl;
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
	if(data.substr(0,2) == "\\q" || data.substr(0,4) == "exit" 
		|| data.substr(0,4) == "quit")
      break;

    stringstream ss;
    ss << data;

    InputParser ip;
    ss >> ip;

    Function fn = UNDEF;
    vector<pair<string,string> > info, cond;
    if(ip.lastInterpret(fn, info, cond) == 0)
      EntityDataBase::Instance().execFromParams(fn, info, cond);

    cout << "#> " << flush;
  }

  if(data.empty())
    cout << "\\q" << endl;

  EntityDataBase::Instance().printEntityDetails();

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
