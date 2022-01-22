#include "../include/database/entityDatabase.h"
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
  memcpy(this, &en, sizeof(EntityDataBase));
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

  for(int i = 0; i < m_allBuildings.size(); i++)
	  delete m_allBuildings[i];
  for(int i = 0; i < m_allPeriods.size(); i++)
	  delete m_allPeriods[i];
  for(int i = 0; i < m_allSections.size(); i++)
	  delete m_allSections[i];
  for(int i = 0; i < m_allTimeTables.size(); i++)
	  delete m_allTimeTables[i];

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
	  lastIndex = m_allBuildings.size();
      m_allBuildings.resize(lastIndex+1);
      m_allBuildings[lastIndex] = new Building();
      m_allBuildings[lastIndex]->addAttrs(attrs); break;
    case FLOOR:
	  lastIndex = m_allFloors.size();
      m_allFloors.resize(lastIndex+1);
      m_allFloors[lastIndex] = new Floor();
      m_allFloors[lastIndex]->addAttrs(attrs); break;
    case CLASS:   
	  lastIndex = m_allClasses.size();
      m_allClasses.resize(lastIndex+1);
      m_allClasses[lastIndex] = new Class();
      m_allClasses[lastIndex]->addAttrs(attrs); break;
	case PERIOD:
	  lastIndex = m_allPeriods.size();
      m_allPeriods.resize(lastIndex+1);
      m_allPeriods[lastIndex] = new Period();
      m_allPeriods[lastIndex]->addAttrs(attrs); break;
    case SECTION: 
	  lastIndex = m_allSections.size();
      m_allSections.resize(lastIndex+1);
      m_allSections[lastIndex] = new Section();
      m_allSections[lastIndex]->addAttrs(attrs); break;
    case SUBJECT: 
	  lastIndex = m_allSubjects.size();
      m_allSubjects.resize(lastIndex+1);
      m_allSubjects[lastIndex] = new Subject();
      m_allSubjects[lastIndex]->addAttrs(attrs); break;
    case TIMETABLE:
	  lastIndex = m_allTimeTables.size();
      m_allTimeTables.resize(lastIndex+1);
      m_allTimeTables[lastIndex] = new TimeTable();
      m_allTimeTables[lastIndex]->addAttrs(attrs); break;
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
    cout << "\t" << m_allTeachers[i] << endl;

  // Printing students details
  cout << "Printing student details: " << endl;
  if(m_allStudents.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allStudents.size(); i++)
    cout << "\t" << m_allStudents[i] << endl;

  // Printing floors details
  cout << "Printing floor details: " << endl;
  if(m_allFloors.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allFloors.size(); i++)
    cout << "\t" << m_allFloors[i] << endl;

  // Printing classes details
  cout << "Printing classes details: " << endl;
  if(m_allClasses.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allClasses.size(); i++)
    cout << "\t" << m_allClasses[i] << endl;

  // Printing subjects details
  cout << "Printing subjects details: " << endl;
  if(m_allSubjects.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allSubjects.size(); i++)
	cout << "\t" << m_allSubjects[i] << endl;

  // Printing building details
  cout << "Printing buildings details: " << endl;
  if(m_allBuildings.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allBuildings.size(); i++)
	cout << "\t" << m_allBuildings[i] << endl;

  // Printing periods details
  cout << "Printing periods details: " << endl;
  if(m_allPeriods.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allPeriods.size(); i++)
	cout << "\t" << m_allPeriods[i] << endl;

  // Printing sections details
  cout << "Printing sections details: " << endl;
  if(m_allSections.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allSections.size(); i++)
	cout << "\t" << m_allSections[i] << endl;

// Printing timetables details
  cout << "Printing timetables details: " << endl;
  if(m_allTimeTables.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allTimeTables.size(); i++)
	cout << "\t" << m_allTimeTables[i] << endl;


  return 0;
}

int EntityDataBase::findEntity() const
{
	return 0;
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
