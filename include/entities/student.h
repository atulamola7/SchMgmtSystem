/**
 * Student Header file
 * Contains all the info about the students present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "class.h"
#include "subject.h"

class Class;
class Subject;

class Student
{
  public:
    Student();
    ~Student();

    friend std::ostream& operator<<(std::ostream&, const Student*);
    friend std::ostream& operator<<(std::ostream&, const Student&);

    friend std::istream& operator>>(std::istream&, Student*);
    friend std::istream& operator>>(std::istream&, Student&);

    friend class EntityDataBase;

  private:
    struct SubjectMarks
    {
      const Subject* subject;
      std::vector<uint16_t> marks;
    };

    std::string m_name;
    float m_avgPercent;

    std::vector<SubjectMarks> _SubjectAndMarks;
    const Class* _Class;
};
