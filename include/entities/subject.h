/**
 * Subject Header file
 * Contains all the info about the subjects present in the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <string>

class Subject
{
  public:
    Subject();
    ~Subject();

    friend std::ostream& operator<<(std::ostream&, const Subject*);
    friend std::ostream& operator<<(std::ostream&, const Subject&);

	int addAttrs(const std::vector<std::pair<std::string, std::string> >&);

    friend std::istream& operator>>(std::istream&, Subject*);
    friend std::istream& operator>>(std::istream&, Subject&);

  private:
    std::string m_name;
};
