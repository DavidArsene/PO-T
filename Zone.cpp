#include "Zone.h"
#include "Util.h"

int Zone::numSeats() const { return (end.col - start.col + 1) * (end.row - start.row + 1); }

Zone Zone::parse(const std::vector<Zone>& zones, char name) {
    for (Zone current : zones) {
        if (current.name == std::toupper(name)) return current;
    }
    throw std::invalid_argument("Invalid zone");
}

Point Zone::parseSeat(std::string_view seat) const {
    int number = std::stoi(seat.substr(1).data());
    if (number < 1 || number > numSeats()) throw std::invalid_argument("Invalid seat number");

    int rowLength = end.row - start.row + 1;
    auto [col, row] = std::div(number - 1, rowLength);

    switch (orientation) {
        case DEG_0:   return { start.col + col, start.row + row };
        case DEG_90:  return { end.col   - row, start.row + col };
        case DEG_180: return { end.col   - col, end.row   - row };
        case DEG_270: return { start.col + row, end.row   - col };
    }

    throw std::invalid_argument("Invalid orientation");
}

int Zone::getSeatNumber(const Point &seat) const {
    int col = seat.col - start.col;
    int row = seat.row - start.row;
    int colLength = end.col - start.col + 1;
    int rowLength = end.row - start.row + 1;
    int colInv = colLength - col;
    int rowInv = rowLength - row;

    switch (orientation) {
        case DEG_0:   return (rowLength * col) + row + 1;
        case DEG_90:  return (colLength * row) + colInv;
        case DEG_180: return (colInv - 1) * rowLength + rowInv;
        case DEG_270: return (rowInv - 1) * colLength + col + 1;
    }

    throw std::invalid_argument("Invalid orientation");
}

std::istream &operator>>(std::istream &is, Zone &zone) {
    zone.name = Util::input<char>("Zone name: ");
    zone.start = Util::input<Point>("Start: \n");
    zone.end = Util::input<Point>("End: \n");
    if (zone.name != Zone::STAGE)
        is >> zone.orientation;
    return is;
}

std::istream &operator>>(std::istream &is, Orientation &orientation) {
    int value = Util::input<int>("Orientation (one of 0, 90, 180, 270): ", [](auto orientation) {
        if (orientation != 0 && orientation != 90 && orientation != 180 && orientation != 270)
            throw std::invalid_argument("Invalid orientation");
    });
    switch (value) {
        case 0:   orientation = DEG_0;   break;
        case 90:  orientation = DEG_90;  break;
        case 180: orientation = DEG_180; break;
        case 270: orientation = DEG_270; break;
        default: throw std::invalid_argument("Invalid orientation");
    }
    return is;
}

std::istream &operator>>(std::istream &is, Point &point) {
    std::cout << "Col: ";
    is >> point.col;
    std::cout << "Row: ";
    is >> point.row;
    if (point.col < 0 || point.row < 0) throw std::invalid_argument("Invalid point");
    if (point.col * point.row >= 1000) throw std::invalid_argument("Too large");
    return is;
}
