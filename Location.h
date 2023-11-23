#pragma once

#include <iostream>
#include <vector>

#include "Zone.h"

class Location {
public: // TODO: getters
    std::string name;
    std::vector<Zone> zones;
    Point area;

public:
    static const int MAX_ZONES = 0xFF;
};
