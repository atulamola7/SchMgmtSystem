/* InputParser
 * This parser will take input string and return interpreted info
 */

#pragma once

#include <vector>
#include <utility>
#include <string>
#include <iostream>

#include "../include/database/entityDatabase.h"

class InputParser
{
  public:
    InputParser();
    ~InputParser();

    friend std::ostream& operator<<(std::ostream&, const InputParser*);
    friend std::ostream& operator<<(std::ostream&, const InputParser&);

    friend std::istream& operator>>(std::istream&, InputParser*);
    friend std::istream& operator>>(std::istream&, InputParser&);

    //int lastInterpret(Function&, std::vector<std::pair<Entity, std::string> >&, std::vector<std::pair<Entity, std::string> >&);
    int lastInterpret(Function&, std::vector<std::pair<std::string, std::string> >&, std::vector<std::pair<std::string, std::string> >&);

  private:
    std::vector<std::string> m_parsedStrings;
};
