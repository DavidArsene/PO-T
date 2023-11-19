#pragma once

#include <iostream>

#include "Zone.cpp"

class Location {
    Zone *zones = {};
    int numZones = 0;
    int areaX = 0;
    int areaY = 0;

public:
    Location(Zone *zones, int numZones, int areaX, int areaY) {
        this->zones = zones;
        this->numZones = numZones;
        this->areaX = areaX;
        this->areaY = areaY;
    }

    friend std::ostream& operator<<(std::ostream& os, const Location& location) {

        for (int i = 0; i < location.areaX; i++) {
            for (int j = 0; j < location.areaY; j++) {
                for (int k = 0; k < location.numZones; k++) {
                    Zone current = location.zones[k];
                    if (i >= current.startX && i <= current.endX && j >= current.startY && j <= current.endY) {
                        int row = i - current.startX;
                        int seat = j - current.startY + 1;
                        int number = row * (current.endY - current.startY + 1) + seat;
                        os << current.name;
                        if (number < 10) os << '0';
                        os << number << ' ';
                        goto skip;
                    }
                }
                os << "┕━━┙";
                skip:
            }
            os << std::endl;
        }
        return os;
    }
};
