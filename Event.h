#pragma once

#include "Location.h"

#include <vector>
#include <array>

class Event {
    Location location;
    std::string name;
    std::vector<bool> seatsTaken;
    std::array<int, Location::MAX_ZONES> prices {};

public:
    // constructors
    Event(const Location& location, std::string name);

    // getters and setters
    const std::string &getName() const;
    void setName(const std::string &name);

    void setSeatStatus(const Point &seat, bool status);
    bool isSeatTaken(const Point &seat) const;

    void setPrice(char zone, int price);
    int getPrice(char zone) const;

    // operators
    friend std::ostream &operator<<(std::ostream &os, const Event &event);

    // methods
    Point parseSeat(const std::string &seat) const;
    void reserveSeat(const std::string &seat);
};
