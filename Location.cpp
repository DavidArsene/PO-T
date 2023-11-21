#include "Location.h"

Location::Location(std::string name, Zone *zones, int numZones, int areaX, int areaY) {
    this->name = std::move(name);
    this->zones = zones;
    this->numZones = numZones;
    this->areaX = areaX;
    this->areaY = areaY;
}
