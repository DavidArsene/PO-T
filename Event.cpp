#include "Event.h"
#include <termcolor.hpp>

std::vector<Event> Event::events;

std::ostream &operator<<(std::ostream &os, const Event &event) {
    Location loc = event.location;
    for (int col = 0; col < loc.getArea().col; col++) {
        for (int row = 0; row < loc.getArea().row; row++) {
            for (Zone current : loc.getZones()) {
                if (col < current.start.col || col > current.end.col
                 || row < current.start.row || row > current.end.row)
                    continue;

                if (current.name == Zone::STAGE) {
                    os << "━━━━";
                    goto skip;
                }
                int number = current.getSeatNumber({ col, row });

                bool taken = event.seatsTaken[loc.getArea().row * col + row];
                if (taken) os << termcolor::red; else os << termcolor::green;

                os << current.name;
                if (number < 10) os << '0';
                os << number << termcolor::reset << ' ';
                goto skip;
            }
            // os << "┕━━┙";
            os << "    ";
            skip:
        }
        os << std::endl;
    }
    os << "Zone prices:\n";
    for (Zone current : loc.getZones()) {
        if (current.name == Zone::STAGE) continue;
        os << current.name << " - " << event.prices[current.name] << std::endl;
    }
    return os;
}

Event::Event(const Location &location, std::string name) : location(location), name(std::move(name)) {
    seatsTaken.resize(location.getArea().col * location.getArea().row);
}

void Event::reserveSeat(std::string_view seat) {
    setSeatStatus(parseSeat(seat), true);
}

Point Event::parseSeat(std::string_view seat) {
    if (seat.length() != 3) throw std::invalid_argument("Invalid seat");
    char zoneName = seat[0];
    if (zoneName == Zone::STAGE) throw std::invalid_argument("You can't buy a seat on the stage, silly!");
    Zone zone = Zone::parse(location.getZones(), zoneName);

    return zone.parseSeat(seat);
}

void Event::setSeatStatus(const Point &seat, bool status) {
    seatsTaken[location.getArea().row * seat.col + seat.row] = status;
}

bool Event::isSeatTaken(const Point &seat) const {
    return seatsTaken[location.getArea().row * seat.col + seat.row];
}

void Event::setPrice(char zone, int price) { prices[std::toupper(zone)] = price; }

int Event::getPrice(char zone) const { return prices[std::toupper(zone)]; }

std::string_view Event::getName() const { return name; }

void Event::setName(std::string_view name) { this->name = name; }

std::istream &operator>>(std::istream &is, Event &event) {
    event.name = Util::input<std::string>("Event name: ");
    std::cout << "Available locations:\n";
    for (int i = 0; const Location& current : Location::locations) {
        std::cout << ++i << ": " << current.getName() << std::endl;
    }
    std::vector<std::string> locationNames;
    int locationIndex = Util::choose(Location::locations.size());
    event.location = Location::locations[locationIndex - 1];
    return is;
}
