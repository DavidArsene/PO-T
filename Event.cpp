#include "Event.h"
#include <termcolor.hpp>

std::ostream &operator<<(std::ostream &os, const Event &event) {
    Location loc = event.location;
    for (int i = 0; i < loc.area.X; i++) {
        for (int j = 0; j < loc.area.Y; j++) {
            for (Zone current : loc.zones) {
                if (i >= current.start.X && i <= current.end.X && j >= current.start.Y && j <= current.end.Y) {
                    if (current.name == Zone::STAGE) {
                        os << "━━━━";
                        goto skip;
                    }
                    int number = current.getSeatNumber({ i,  j });

                    bool taken = event.seatsTaken[loc.area.Y * i + j];
                    if (taken) os << termcolor::red;
                    else os << termcolor::green;

                    os << current.name;
                    if (number < 10) os << '0';
                    os << number << termcolor::reset << ' ';
                    goto skip;
                }
            }
#if false
            os << "┕━━┙";
#else
            os << "    ";
#endif
            skip:
        }
        os << std::endl;
    }
    os << "Zone prices:\n";
    for (Zone current : loc.zones) {
        if (current.name == Zone::STAGE) continue;
        os << current.name << " - " << event.prices[current.name] << std::endl;
    }
    return os;
}

Event::Event(const Location &location, std::string name) : location(location), name(std::move(name)) {
    seatsTaken.resize(location.area.X * location.area.Y);
}

void Event::reserveSeat(const std::string &seat) {
    setSeatStatus(parseSeat(seat), true);
}

Point Event::parseSeat(const std::string &seat) const {
    if (seat.length() != 3) throw std::invalid_argument("Invalid seat");
    char zoneName = seat[0];
    if (zoneName == Zone::STAGE) throw std::invalid_argument("You can't buy a seat on the stage, silly!");
    Zone zone = Zone::parse(location.zones, zoneName);

    return zone.parseSeat(seat);
}

void Event::setSeatStatus(const Point &seat, bool status) {
    seatsTaken[location.area.Y * seat.X + seat.Y] = status;
}

bool Event::isSeatTaken(const Point &seat) const {
    return seatsTaken[location.area.Y * seat.X + seat.Y];
}

void Event::setPrice(char zone, int price) { prices[std::toupper(zone)] = price; }

int Event::getPrice(char zone) const { return prices[std::toupper(zone)]; }

const std::string &Event::getName() const { return name; }

void Event::setName(const std::string &name) { this->name = name; }
