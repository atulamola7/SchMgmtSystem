#pragma once

#include <string>

class StringEx
{
  public:
    static std::string replaceAll(std::string str, const std::string& toBeReplaced, const std::string& replaceWith);
};
