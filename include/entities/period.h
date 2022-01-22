/**
 * Period Header file
 * Contains all the info about the periods
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "period.h"
#include "class.h"
#include "subject.h"
#include "teacher.h"

class Teacher;
class Class;
class Subject;

class Period
{
  public:
    Period();
    ~Period();

    friend std::ostream& operator<<(std::ostream&, const Period*);
    friend std::ostream& operator<<(std::ostream&, const Period&);

    friend std::istream& operator>>(std::istream&, Period*);
    friend std::istream& operator>>(std::istream&, Period&);

	int addAttrs(const std::vector<std::pair<std::string, std::string> >&);

    friend class EntityDataBase;


  private:
    std::string m_startTime;
    std::string m_endTime;

    const Class* _Class;
    const Teacher* _Teacher;
    const Subject* _Subject;
};
