#pragma once

#include <iostream>

#include "entityDatabase.h"
#include "inputParser.h"

class SchoolManager
{
  public:
    SchoolManager();
    ~SchoolManager();

    int init();
    int run();

  private:

    int loadInfoFromFiles();
};
