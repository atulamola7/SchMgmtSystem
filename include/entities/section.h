/**
 * Class-section Header file
 * Contains all the info about the class sections present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#if defined(WIN32) || defined(WIN64)
#define uint16_t __int16
#else
#include <stdint.h>
#endif

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

	int addAttrs(const std::vector<std::pair<std::string, std::string> >&);

    friend class EntityDataBase;

  private:
    std::string m_name;
    uint16_t m_maxOccupancy;
    uint16_t m_roomNo;

    std::vector<const Student*> _Students;
    const TimeTable* _TimeTable;
    const Class* _Class;
};
