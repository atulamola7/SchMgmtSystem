/**
 * Database Header file
 * Contains all the info about the entities present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "teacher.h"
#include "student.h"
#include "floor.h"
#include "class.h"
#include "subject.h"

enum Function
{
  UNDEF  = 0,
  ADD    = 1,
  FIND   = 2,
  LINK   = 3,
  DELETE = 4,
  PRINT  = 5
};

enum Entity
{
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

    int addNewEntity(Entity entity, const std::string& name);
    int linkEntity();
    int deleteEntity();
    int printEntityDetails() const;
    int printAllEntityDetails() const;
    int findEntity() const;

  private:
    std::vector<Teacher*> m_allTeachers;
    std::vector<Student*> m_allStudents;
    std::vector<Subject*> m_allSubjects;
    std::vector<Class*>   m_allClasses;
    std::vector<Floor*>   m_allFloors;
};
