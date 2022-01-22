#pragma once

#include <string>
#include <vector>

class StringEx
{
  public:
    static std::string replaceAll(std::string str, const std::string& toBeReplaced, const std::string& replaceWith);
	static std::vector<std::string> split(std::string str, const std::string& delimiter);
};
