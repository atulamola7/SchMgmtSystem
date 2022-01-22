/**
 * timetable Header file
 * Contains all the info about the timetables of classes + teachers present in the school
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "period.h"

class Period;
class Section;

class TimeTable
{
  public:
    TimeTable();
    ~TimeTable();

    friend std::ostream& operator<<(std::ostream&, const TimeTable*);
    friend std::ostream& operator<<(std::ostream&, const TimeTable&);

    friend std::istream& operator>>(std::istream&, TimeTable*);
    friend std::istream& operator>>(std::istream&, TimeTable&);

	int addAttrs(const std::vector<std::pair<std::string, std::string> >&);

    friend class EntityDataBase;

  private:
    Section* _Section;
	std::string m_id;
    std::vector<const Period*> _Periods;
};
