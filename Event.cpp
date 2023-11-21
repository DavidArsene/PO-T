#include "Event.h"
#include <termcolor.hpp>

std::ostream &operator<<(std::ostream &os, const Event &event) {
    Location loc = event.location;
    for (int i = 0; i < loc.areaX; i++) {
        for (int j = 0; j < loc.areaY; j++) {
            for (Zone current : loc.zones) {
                if (i >= current.start.X && i <= current.end.X && j >= current.start.Y && j <= current.end.Y) {
                    int row = i - current.start.X;
                    int seat = j - current.start.Y + 1;
                    int number = row * (current.end.Y - current.start.Y + 1) + seat;

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
    os << "Zone prices:\n";
    for (Zone current : loc.zones) {
        os << current.name << " - " << event.prices[current.name] << std::endl;
    }
    return os;
}

Event::Event(const Location &location, std::string name) : location(location), name(std::move(name)) {
    seatsTaken.resize(location.areaX * location.areaY);
}

void Event::reserveSeat(const std::string &seat) {
    if (seat.length() != 3) throw std::invalid_argument("Invalid seat");
    char zoneName = seat[0];
    Zone zone = Zone::parse(location.zones, zoneName);

    Point seat2 = zone.parseSeat(seat);
    seatsTaken[location.areaY * seat2.X + seat2.Y] = true;
}

void Event::setPrice(char zone, int price) { prices[zone] = price; }
