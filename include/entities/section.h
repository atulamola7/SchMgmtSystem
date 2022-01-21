/**
 * Class-section Header file
 * Contains all the info about the class sections present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

#include "timetable.h"

class TimeTable;
class Student;
class Class;

class Section
{
  public:
    Section();
    ~Section();

    friend std::ostream& operator<<(std::ostream&, const Section*);
    friend std::ostream& operator<<(std::ostream&, const Section&);

    friend std::istream& operator>>(std::istream&, Section*);
    friend std::istream& operator>>(std::istream&, Section&);

    friend class EntityDataBase;

  private:
    std::string m_name;
    uint16_t m_maxOccupancy;
    uint16_t m_roomNo;

    std::vector<const Student*> _Students;
    const TimeTable* _TimeTable;
    const Class* _Class;
};
