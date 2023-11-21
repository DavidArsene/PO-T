#pragma once

#include <iostream>
#include <vector>

enum Orientation { HORIZONTAL, VERTICAL };
struct Point { int X = 0, Y = 0; };

class Zone {
public:
    char name = 'X';
    Point start, end;
    Orientation orientation = HORIZONTAL;

public:
    int numSeats() const;

    static Zone parse(std::vector<Zone> zones, char name);
    Point parseSeat(const std::string& seat) const;
};
