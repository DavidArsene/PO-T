#pragma once

#include <iostream>
#include <vector>

#include "Zone.h"

class Location {
    std::string name;
    std::vector<Zone> zones;
    Point area;

    friend class Event;

public:
    static const int MAX_ZONES = 0xFF;

    // constructors
    Location() = default;
    Location(std::string_view name, Point area);
    Location(std::string_view name, std::vector<Zone> zones, Point area);

    // getters and setters
    std::string_view getName() const;
    void setName(std::string_view name);

    std::vector<Zone> &getZones();

    const Point &getArea() const;
    void setArea(Point area);

    friend std::ostream &operator<<(std::ostream &os, const Location &location);
    friend std::istream &operator>>(std::istream &is, Location &location);
};
