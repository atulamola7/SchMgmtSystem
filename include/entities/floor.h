/**
 * Floor Header file
 * Contains all the info about the floors present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Class;

class Floor
{
  public:
    Floor();
    ~Floor();

    friend std::ostream& operator<<(std::ostream&, const Floor*);
    friend std::ostream& operator<<(std::ostream&, const Floor&);

    friend std::istream& operator>>(std::istream&, Floor*);
    friend std::istream& operator>>(std::istream&, Floor&);

	int addAttrs(const std::vector<std::pair<std::string, std::string> >&);

    friend class EntityDataBase;


  private:
    std::string m_name;
    std::vector<const Class*> _ClassRooms;
};
