/**
 * timetable Header file
 * Contains all the info about the timetables of classes + teachers present in the school
 */

#pragma once

#include <iostream>
#include <vector>

#include "period.h"

class Period;

class TimeTable
{
  public:
    TimeTable();
    ~TimeTable();

    friend std::ostream& operator<<(std::ostream&, const TimeTable*);
    friend std::ostream& operator<<(std::ostream&, const TimeTable&);

    friend std::istream& operator>>(std::istream&, TimeTable*);
    friend std::istream& operator>>(std::istream&, TimeTable&);

    friend class EntityDataBase;

  private:

    std::vector<const Period*> _Periods;
};
