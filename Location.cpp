#include "Location.h"
#include "Util.h"

std::vector<Location> Location::locations;

std::string_view Location::getName() const { return name; }
void Location::setName(std::string_view name) { this->name = name; }

std::vector<Zone> &Location::getZones() { return zones; }

const Point &Location::getArea() const { return area; }
void Location::setArea(Point area) { this->area = area; }

std::ostream &operator<<(std::ostream &os, const Location &location) {
    for (int col = 0; col < location.area.col; col++) {
        for (int row = 0; row < location.area.row; row++) {
            os << col << ',' << row << '\t';
        }
        os << std::endl;
    }
    return os;
}

Location::Location(std::string_view name, Point area) : name(name) {
    setArea(area);
}

Location::Location(std::string_view name, std::vector<Zone> zones, Point area) : Location(name, area) {
    this->zones = std::move(zones);
}

std::istream &operator>>(std::istream &is, Location &location) {
    location.name = Util::input<std::string>("Location name: ");
    location.area = Util::input<Point>("Area: \n");
    std::cout << location;
    int numZones = Util::input<int>("Number of zones: ", [](auto num) {
        if (num < 0) throw std::invalid_argument("Invalid number of zones");
    });
    location.zones.resize(numZones);
    for (Zone& zone : location.zones) {
        is >> zone;
    }
    return is;
}
