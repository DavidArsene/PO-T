#pragma once

#include <iostream>
#include <vector>
#include "Util.h"

enum Orientation { DEG_0, DEG_90, DEG_180, DEG_270 };

std::istream &operator>>(std::istream &is, Orientation &orientation);

struct Point { int col = 0, row = 0; };

std::istream &operator>>(std::istream &is, Point &point);

class Zone {
public:
    char name = 'X';
    Point start, end;
    Orientation orientation = DEG_0;

public:
    int numSeats() const;

    // methods
    static Zone parse(const std::vector<Zone>& zones, char name);
    Point parseSeat(std::string_view seat) const;
    int getSeatNumber(const Point& seat) const;

    friend std::istream &operator>>(std::istream &is, Zone &zone);

    static const char STAGE = '-';
};
