#pragma once

#include <iostream>

#include "../include/database/entityDatabase.h"
#include "../include/manager/inputParser.h"

class SchoolManager
{
  public:
    SchoolManager();
    ~SchoolManager();

    int init();
    int run();
};
