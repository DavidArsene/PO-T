#pragma once

#include "Location.h"

#include <vector>
#include <array>

class Event {
    Location location;
    std::string name;
    std::vector<bool> seatsTaken;
    std::array<int, 0xFF> prices {};

public:
    Event(const Location& location, std::string name);

    friend std::ostream &operator<<(std::ostream &os, const Event &event);

    void reserveSeat(const std::string &seat);

    void setPrice(char zone, int price);
};
