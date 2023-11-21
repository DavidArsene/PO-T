#include "Event.h"
#include <termcolor.hpp>

std::ostream &operator<<(std::ostream &os, const Event &event) {
    Location loc = event.location;
    for (int i = 0; i < loc.areaX; i++) {
        for (int j = 0; j < loc.areaY; j++) {
            for (int k = 0; k < loc.numZones; k++) {
                Zone current = loc.zones[k];
                if (i >= current.startX && i <= current.endX && j >= current.startY && j <= current.endY) {
                    int row = i - current.startX;
                    int seat = j - current.startY + 1;
                    int number = row * (current.endY - current.startY + 1) + seat;

                    bool taken = event.seatsTaken[loc.areaY * i + j];
                    if (taken) os << termcolor::red;
                    else os << termcolor::green;

                    os << current.name;
                    if (number < 10) os << '0';
                    os << number << termcolor::reset << ' ';
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

Event::Event(const Location& location, std::string name) : location(location), name(std::move(name)) {
    seatsTaken.reserve(location.areaX * location.areaY);
}

void Event::reserveSeat(int x, int y) {
    seatsTaken[location.areaY * x + y] = true;
}
