/**
 * Teacher Header file
 * Contains all the info about the teachers present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <string>

class Subject;
class TimeTable;

class Teacher
{
  public:
    Teacher();
    ~Teacher();

    friend std::ostream& operator<<(std::ostream&, const Teacher*);
    friend std::ostream& operator<<(std::ostream&, const Teacher&);

    friend std::istream& operator>>(std::istream&, Teacher*);
    friend std::istream& operator>>(std::istream&, Teacher&);

    int addAttrs(const std::vector<std::pair<std::string, std::string> >&);

    friend class EntityDataBase;

  private:
    std::string m_name;
    std::string m_tchrId;

    const Subject* _Subject;
    const TimeTable* _TeacherTT;
};
