#pragma once

#include "Location.h"

#include <vector>

class Event {
    Location location;
    std::string name;
    std::vector<bool> seatsTaken;

public:
    Event(const Location& location, std::string name);

    friend std::ostream &operator<<(std::ostream &os, const Event &event);

    void reserveSeat(int x, int y);
};
