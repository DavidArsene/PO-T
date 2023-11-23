#include "Zone.h"

int Zone::numSeats() const { return (end.X - start.X + 1) * (end.Y - start.Y + 1); }

Zone Zone::parse(const std::vector<Zone>& zones, char name) {
    for (Zone current : zones) {
        if (current.name == std::toupper(name)) return current;
    }
    throw std::invalid_argument("Invalid zone");
}

Point Zone::parseSeat(const std::string &seat) const {
    int number = std::stoi(seat.substr(1));
    if (number < 1 || number > numSeats()) throw std::invalid_argument("Invalid seat number");
    int rowLength = end.Y - start.Y + 1;
    div_t division = std::div(number - 1, rowLength);
    return {start.X + division.quot, start.Y + division.rem };
}

int Zone::getSeatNumber(const Point &seat) const {
    int col = seat.X - start.X;
    int row = seat.Y - start.Y;
    int colLength = end.X - start.X + 1;
    int rowLength = end.Y - start.Y + 1;
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
