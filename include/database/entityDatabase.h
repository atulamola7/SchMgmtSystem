/**
 * Database Header file
 * Contains all the info about the entities present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "../include/entities/teacher.h"
#include "../include/entities/student.h"
#include "../include/entities/floor.h"
#include "../include/entities/class.h"
#include "../include/entities/subject.h"
#include "../include/entities/building.h"
#include "../include/entities/section.h"
#include "../include/entities/period.h"
#include "../include/entities/timetable.h"

enum Function
{
  UNDEF  = 0,
  ADD    = 1,
  UPDATE = 2,
  FIND   = 3,
  LINK   = 4,
  DELETE = 5,
  PRINT  = 6
};

enum Entity
{
  ALL,
  BUILDING,
  FLOOR,
  CLASS,
  PERIOD,
  SECTION,
  SUBJECT,
  TEACHER,
  STUDENT,
  TIMETABLE
};

class EntityDataBase
{
  public:
    static EntityDataBase& Instance();
    ~EntityDataBase();

    int execFromParams(Function fn, const std::vector<std::pair<std::string, std::string> >&, const std::vector<std::pair<std::string, std::string> >&);

    static Entity getEntityFromStr(const std::string&);
    static Function getFunctionFromStr(const std::string&);
    static std::string getStringFromEntity(const Entity&);
    static std::string getStringFromFunction(const Function&);

    // TODO Move to private
    int printEntityDetails() const;
    int printAllEntityDetails() const;

  private:
    EntityDataBase();
    EntityDataBase(const EntityDataBase&);
    const EntityDataBase& operator=(const EntityDataBase&);

    static char* m_functionStr[PRINT+1];
    static char* m_entityStr[TIMETABLE+1];

    int addNewEntity(Entity entity, const std::vector<std::pair<std::string, std::string> >&);
    int linkEntity();
    int deleteEntity();
    int findEntity() const;

    std::vector<Teacher*> m_allTeachers;
    std::vector<Student*> m_allStudents;
    std::vector<Subject*> m_allSubjects;
    std::vector<Class*>   m_allClasses;
    std::vector<Floor*>   m_allFloors;

	std::vector<Building*> m_allBuildings;
	std::vector<Period*>   m_allPeriods;
	std::vector<Section*>  m_allSections;
	std::vector<TimeTable*>  m_allTimeTables;
};
