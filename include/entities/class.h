/**
 * Class Header file
 * Contains all the info about the classes present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "section.h"

class Section;

class Class
{
  public:
    Class();
    ~Class();

    friend std::ostream& operator<<(std::ostream&, const Class*);
    friend std::ostream& operator<<(std::ostream&, const Class&);

    friend std::istream& operator>>(std::istream&, Class*);
    friend std::istream& operator>>(std::istream&, Class&);

	int addAttrs(const std::vector<std::pair<std::string, std::string> >&);

    friend class EntityDataBase;

  private:
    std::string m_name;
    std::vector<const Section*> _Sections;
};
