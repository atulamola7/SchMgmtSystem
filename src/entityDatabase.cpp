#include "entityDatabase.h"
using namespace std;

// Populate FunctionStr
char* EntityDataBase::m_functionStr[PRINT+1] = {
  "Undefined",
  "ADD",
  "UPDATE",
  "FIND",
  "LINK",
  "DELETE",
  "PRINT"
};
// Populate EntityStr
char* EntityDataBase::m_entityStr[TIMETABLE+1] = {
  "ALL",
  "BUILDING",
  "FLOOR",
  "CLASS",
  "PERIOD",
  "SECTION",
  "SUBJECT",
  "TEACHER",
  "STUDENT",
  "TIMETABLE"
};

EntityDataBase::EntityDataBase()
{
}

EntityDataBase::EntityDataBase(const EntityDataBase& en)
{
  *this = en;
}

const EntityDataBase& EntityDataBase::operator=(const EntityDataBase& en)
{
  *this = en;
  return *this;
}

EntityDataBase& EntityDataBase::Instance()
{
  static EntityDataBase eDB;
  return eDB;
}

EntityDataBase::~EntityDataBase()
{
  for(int i = 0; i < m_allTeachers.size(); i++)
    delete m_allTeachers[i];
  for(int i = 0; i < m_allStudents.size(); i++)
    delete m_allStudents[i];
  for(int i = 0; i < m_allSubjects.size(); i++)
    delete m_allSubjects[i];
  for(int i = 0; i < m_allClasses.size(); i++)
    delete m_allClasses[i];
  for(int i = 0; i < m_allFloors.size(); i++)
    delete m_allFloors[i];
}

int EntityDataBase::execFromParams(Function fn, const vector<pair<string, string> >& info, const vector<pair<string, string> >& cond)
{
  // Condition is true; when there is ADD, but no linking
  if(fn == ADD && cond.empty())
  {
    Entity en = ALL;
    for(int i = 0; i < info.size() && (en = getEntityFromStr(info[i].second)) == ALL; i++);
    addNewEntity(en, info);
  }
  else if(fn == ADD)
  {
    cout << "ERROR: " << m_functionStr[fn] << " with LINKING not implemented yet!" << endl;
  }
  else
  {
    cout << "ERROR: " << m_functionStr[fn] << " not implemented yet!" << endl;
  }
  return 0;
}

int EntityDataBase::addNewEntity(Entity entity, const std::vector<std::pair<std::string, std::string> >& attrs)
{
  int lastIndex = -1;

  switch(entity)
  {
    case STUDENT:
      lastIndex = m_allStudents.size();
      m_allStudents.resize(lastIndex+1);
      m_allStudents[lastIndex] = new Student();
      m_allStudents[lastIndex]->addAttrs(attrs); break;
    case TEACHER:
      lastIndex = m_allTeachers.size();
      m_allTeachers.resize(lastIndex+1);
      m_allTeachers[lastIndex] = new Teacher();
      m_allTeachers[lastIndex]->addAttrs(attrs); break;
    case BUILDING:
    case FLOOR:
    case CLASS:   
    case PERIOD:
    case SECTION: 
    case SUBJECT: 
    case TIMETABLE:
    default:
      cout << "ERROR: Not an entity!" << endl;
      return -1;
  }

  cout << "INFO: New entity added!" << endl;
  return 0;
}

int EntityDataBase::linkEntity()
{
  return 0;
}

int EntityDataBase::deleteEntity()
{
  return 0;
}

int EntityDataBase::printEntityDetails() const
{
  // Printing Teacher details
  cout << "Printing teacher details: " << endl;
  if(m_allTeachers.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allTeachers.size(); i++)
  {
    cout << "\t" << m_allTeachers[i] << endl;
  }
  // Printing students details
  cout << "Printing student details: " << endl;
  if(m_allStudents.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allStudents.size(); i++)
  {
    cout << "\t" << m_allStudents[i] << endl;
  }

  return 0;
}

int EntityDataBase::findEntity() const
{
}

Entity EntityDataBase::getEntityFromStr(const string& str)
{
  for(int i = 0; i <= TIMETABLE; i++)
    if(str == m_entityStr[i])
      return (Entity)i;
  return ALL;
}

Function EntityDataBase::getFunctionFromStr(const string& str)
{
  for(int i = 0; i <= PRINT; i++)
    if(str == m_functionStr[i])
      return (Function)i;
  return UNDEF;
}

string EntityDataBase::getStringFromEntity(const Entity& en)
{
  return m_entityStr[en];
}

string EntityDataBase::getStringFromFunction(const Function& fn)
{
  return m_functionStr[fn];
}
