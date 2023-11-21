#include "Zone.h"

int Zone::numSeats() const {
    return (end.X - start.X + 1) * (end.Y - start.Y + 1);
}

Zone Zone::parse(std::vector<Zone> zones, char name) {

    int zoneIndex = -1;
    for (int i = 0; i < zones.size(); i++) {
        if (zones[i].name == name) {
            zoneIndex = i;
            break;
        }
    }
    if (zoneIndex == -1) throw std::invalid_argument("Invalid zone");
    return zones[zoneIndex];
}

Point Zone::parseSeat(const std::string &seat) const {
    int number = std::stoi(seat.substr(1));
    if (number < 1 || number > numSeats()) throw std::invalid_argument("Invalid seat number");
    int rowLength = end.Y - start.Y + 1;
    div_t division = std::div(number - 1, rowLength);
    return {start.X + division.quot, start.Y + division.rem };
}

