#include "../include/database/entityDatabase.h"
using namespace std;

// Populate FunctionStr
const char* EntityDataBase::m_functionStr[HELP+1] = {
  "Undefined",
  "ADD",
  "UPDATE",
  "FIND",
  "LINK",
  "DELETE",
  "PRINT",
  "HELP"
};
// Populate EntityStr
const char* EntityDataBase::m_entityStr[TIMETABLE+1] = {
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
  int ret = 0;
  // Condition is true; when there is ADD, but no linking
  if(fn == ADD && cond.empty())
  {
    Entity en = ALL;
	int i;
    for(i = 0; i < info.size() && (en = getEntityFromStr(info[i].second)) == ALL; i++);
	if(info.empty() || info[0].second.empty())
	  cout << "ERROR: Entity not provided!" << endl;
	else if(en == ALL)
	  cout << "ERROR: Entity '" << info[0].second << "' not found!" << endl;

    addNewEntity(en, info);
  }
  else if(fn == ADD)
  {
    cout << "ERROR: " << m_functionStr[fn] << " with LINKING not implemented yet!" << endl;
  }
  else if(fn == LINK)
  {
	cout << "ERROR: Yeah keep trying!" << endl;
  }
  else if(fn == UPDATE)
  {
	cout << "ERROR: Not gonna work, pal!" << endl;
  }
  else if(fn == FIND)
  {
	cout << "ERROR: Yeah yeah, whatever!" << endl;
  }
  else if(fn == DELETE)
  {
	cout << "ERROR: Whatever!" << endl;
  }
  else if(fn == PRINT)
  {
	cout << "ERROR: Don't even try!" << endl;
  }
  else if(fn == HELP)
  {
	  Entity en = info.size() ? getEntityFromStr(info[0].second) : ALL;
	  Function fn = info.size() ? getFunctionFromStr(info[0].second) : UNDEF;
	  printHelp(fn, en);
  }
  else
  {
	ret = -1;
    cout << "ERROR: " << m_functionStr[fn] << " not implemented yet!" << endl;
  }

  return ret;
}

int EntityDataBase::addNewEntity(Entity entity, const std::vector<std::pair<std::string, std::string> >& attrs)
{
  int lastIndex = -1;
  linkEntity();

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
      return -1;
  }

  cout << "INFO: New entity added!" << endl;
  return 0;
}

int EntityDataBase::linkEntity()
{
	cout << "ERROR: '" << __FUNCTION__ << "': Not implemented yet!" << endl;
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
  for(int i = 0; i <= HELP; i++)
    if(str == m_functionStr[i])
      return (Function)i;
  return UNDEF;
}

const char* EntityDataBase::getStringFromEntity(const Entity& en)
{
  return m_entityStr[en];
}

const char* EntityDataBase::getStringFromFunction(const Function& fn)
{
  return m_functionStr[fn];
}

int EntityDataBase::printHelp(Function fn, Entity en)
{
	switch(fn)
	{
		case ADD:		return helpADD();
		case UPDATE:	return helpUPDATE();
		case FIND:		return helpFIND();
		case LINK:		return helpLINK();
		case DELETE:	return helpDELETE();
		case PRINT:		return helpPRINT();
	}

	switch(en)
	{
		case BUILDING:  return helpBUILDING();
		case FLOOR:		return helpFLOOR();
		case CLASS:		return helpCLASS();
		case PERIOD:	return helpPERIOD();
		case SECTION:	return helpSECTION();
		case SUBJECT:	return helpSUBJECT();
		case TEACHER:	return helpTEACHER();
		case STUDENT:	return helpSTUDENT();
		case TIMETABLE:	return helpTIMETABLE();
		case ALL:	cout << "  [HELP]\n\tUsage: HELP <ENTITY>/<FUNCTION>" << endl;
	}

	return -1;
}

int EntityDataBase::helpADD()
{
	cout << "  [HELP]\n\tFunction: ADD" << endl;
	cout << "\tDescription: Adds a new entity element with specified properties and optionally links it to required entity!" << endl;
	cout << "\tUsage: ADD <ENTITY> <ENTITY-SPECIFIC-PROPERTIES> [ FOR <ENTITY> <ENTITY-SPECIFIC-PROPERTIES> ]" << endl;
	return 0;
}

int EntityDataBase::helpUPDATE()
{
	cout << "  [HELP]\n\tFunction: UPDATE" << endl;
	cout << "\tDescription: Updates an already existing entity with new data!" << endl;
	cout << "\tUsage: UPDATE <NEW-ENTITY-SPECIFIC-PROPERTIES> FOR <ENTITY> <OLD-ENTITY-SPECIFIC-PROPERTIES>" << endl;
	return 0;
}

int EntityDataBase::helpFIND()
{
	cout << "  [HELP]\n\tFunction: FIND" << endl;
	cout << "\tDescription: Finds an entity with specific property; can be used for linking complex entities!" << endl;
	cout << "\tUsage: FIND <ENTITY> <ENTITY-SPECIFIC-PROPERTIES>" << endl;
	return 0;
}

int EntityDataBase::helpLINK()
{
	cout << "  [HELP]\n\tFunction: LINK" << endl;
	cout << "\tDescription: LINK - TBD" << endl;
	cout << "\tUsage: LINK : Not decided yet!" << endl;
	return 0;
}

int EntityDataBase::helpDELETE()
{
	cout << "  [HELP]\n\tFunction: DELETE" << endl;
	cout << "\tDescription: Deletes elements with element properties; need to be extended with conditional linked element!" << endl;
	cout << "\t             For example: we want to delete X of class XII-A and not XII-B" << endl;
	cout << "\tUsage: DELETE <ENTITY> <ENTITY-SPECIFIC-PROPERTIES>" << endl;
	return 0;
}

int EntityDataBase::helpPRINT()
{
	cout << "  [HELP]\n\tFunction: PRINT" << endl;
	cout << "\tDescription: Prints info of all entities found in the database with matching properties!" << endl;
	cout << "\tUsage: PRINT <ENTITY> <ENTITY-SPECIFIC-PROPERTIES>" << endl;
	return 0;
}

int EntityDataBase::helpBUILDING()
{
	cout << "  [HELP]\n\tEntity: BUILDING" << endl;
	return 0;
}

int EntityDataBase::helpFLOOR()
{
	cout << "  [HELP]\n\tEntity: FLOOR" << endl;
	return 0;
}

int EntityDataBase::helpCLASS()
{
	cout << "  [HELP]\n\tEntity: CLASS" << endl;
	return 0;
}

int EntityDataBase::helpPERIOD()
{
	cout << "  [HELP]\n\tEntity: PERIOD" << endl;
	return 0;
}

int EntityDataBase::helpSECTION()
{
	cout << "  [HELP}\n\tEntity: SECTION" << endl;
	return 0;
}

int EntityDataBase::helpSUBJECT()
{
	cout << "  [HELP]\n\tEntity: SUBJECT" << endl;
	return 0;
}

int EntityDataBase::helpTEACHER()
{
	cout << "  [HELP]\n\tEntity: TEACHER" << endl;
	return 0;
}

int EntityDataBase::helpSTUDENT()
{
	cout << "  [HELP]\n\tEntity: STUDENT" << endl;
	return 0;
}

int EntityDataBase::helpTIMETABLE()
{
	cout << "  [HELP]\n\tEntity: TIMETABLE" << endl;
	return 0;
}
