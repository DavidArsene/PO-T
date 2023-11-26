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
    static std::vector<Event> events;

    // constructors
    Event() = default;
    Event(const Location& location, std::string name);

    // getters and setters
    std::string_view getName() const;
    void setName(std::string_view name);

    void setSeatStatus(const Point &seat, bool status);
    bool isSeatTaken(const Point &seat) const;

    void setPrice(char zone, int price);
    int getPrice(char zone) const;

    // operators
    friend std::ostream &operator<<(std::ostream &os, const Event &event);
    friend std::istream &operator>>(std::istream &is, Event &event);

    // methods
    Point parseSeat(std::string_view seat);
    void reserveSeat(std::string_view seat);
};
