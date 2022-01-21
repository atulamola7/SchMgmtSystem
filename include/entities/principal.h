/**
 * Principal Header file
 * Contains all the info about the principal of the school
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>

class Principal
{
  public:
    Principal();
    ~Principal();

    friend std::ostream& operator<<(std::ostream&, const Principal*);
    friend std::ostream& operator<<(std::ostream&, const Principal&);

    friend std::istream& operator>>(std::istream&, Principal*);
    friend std::istream& operator>>(std::istream&, Principal&);

  private:
    struct PDetails
    {
      std::string name;
      std::string startTime;
      std::string endTime;
    };

    std::vector<PDetails> m_principals;
};
