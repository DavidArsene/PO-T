#pragma once

#include <iostream>
#include <vector>

enum Orientation { DEG_0, DEG_90, DEG_180, DEG_270 };
struct Point { int X = 0, Y = 0; };

class Zone {
public:
    char name = 'X';
    Point start, end;
    Orientation orientation = DEG_0;

public:
    int numSeats() const;

    static Zone parse(const std::vector<Zone>& zones, char name);
    Point parseSeat(const std::string& seat) const;
    int getSeatNumber(const Point& seat) const;

    static const char STAGE = '-';
};
