#pragma once

#include <iostream>

#include "Zone.h"

class Location {
public: // TODO: getters
    std::string name;
    Zone *zones = {};
    int numZones = 0;
    int areaX = 0;
    int areaY = 0;


public:
    Location(std::string name, Zone *zones, int numZones, int areaX, int areaY);
};
