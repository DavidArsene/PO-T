#include "Zone.h"

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
