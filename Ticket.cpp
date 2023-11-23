#include "Ticket.h"

std::istream &operator>>(std::istream &is, Ticket &ticket) {
    std::cout << "Your name: ";
    is >> ticket.name;
    std::cout << "Seat: ";
    is >> ticket.seat;
    Point seat = ticket.event.parseSeat(ticket.seat);
    if (ticket.event.isSeatTaken(seat)) throw std::invalid_argument("Seat taken");
    std::cout << "Price: " << ticket.event.getPrice(ticket.seat[0]) << std::endl;
    std::cout << "Confirm? (y/n): ";
    char confirm;
    is >> confirm;
    if (confirm == 'y') ticket.event.reserveSeat(ticket.seat);
    else std::cout << "Cancelled\n";
    std::cout << ticket.event;
    return is;
}

Ticket::Ticket(Event event) : event(std::move(event)) {}

std::ostream &operator<<(std::ostream &os, const Ticket &ticket) {
    os << "Ticket for " << ticket.name << " at event " << ticket.event.getName() << " in " << "ticket.event.location.name" << std::endl;
    return os;
}
