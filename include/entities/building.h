/**
 * Building Header file
 * Contains all the info about the buildings present in the school
 */

#pragma once
#include <string>
#include <iostream>
#include <vector>

class Building
{
  public:
    Building();
    ~Building();

    friend std::ostream& operator<<(std::ostream&, const Building*);
    friend std::ostream& operator<<(std::ostream&, const Building&);

    friend std::istream& operator>>(std::istream&, Building*);
    friend std::istream& operator>>(std::istream&, Building&);

    friend class EntityDataBase;

  private:
    std::string m_name;
    std::vector<std::string> m_allLevels; // like LKG, UKG, I, II .... XII
    float m_buildingArea;
};
