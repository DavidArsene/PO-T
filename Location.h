#pragma once

#include <iostream>
#include <vector>

#include "Zone.h"

class Location {
public: // TODO: getters
    std::string name;
    std::vector<Zone> zones;
    int areaX = 0;
    int areaY = 0;
};
