/**
 * Database Header file
 * Contains all the info about the entities present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "teacher.h"
#include "student.h"
#include "floor.h"
#include "class.h"
#include "subject.h"

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
    EntityDataBase();
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
};
