#pragma once

#include "Event.h"

#include <string>

class Ticket {
    Event event;
    std::string name;
    std::string seat;

public:
    Ticket(Event event);

    friend std::ostream &operator<<(std::ostream &os, const Ticket &ticket);
    friend std::istream &operator>>(std::istream &is, Ticket &ticket);
};
