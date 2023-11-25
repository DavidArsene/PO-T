#include "Ticket.h"
#include "Util.h"

std::istream &operator>>(std::istream &is, Ticket &ticket) {
    ticket.name = Util::input<std::string>("Your name: ", [](auto name) {
        if (name.empty()) throw std::invalid_argument("Name cannot be empty");
        if (name.size() < 3) throw std::invalid_argument("Name too short");
    });

    ticket.seat = Util::input<std::string>("Seat: ", [&ticket](auto seat_input) {
        Point seat = ticket.event.parseSeat(seat_input);
        if (ticket.event.isSeatTaken(seat)) throw std::invalid_argument("Seat taken");
    });

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
