#include <iostream>

#include "Location.h"
#include "Event.h"
#include "Ticket.h"

int main() {
    Location location {
            "Ateneul Roman",
            std::vector<Zone> {
                    Zone { 'A', { 1, 4  }, { 5, 13 }, DEG_180 },
                    Zone { 'B', { 6, 1  }, { 8, 3  }, DEG_270 },
                    Zone { 'C', { 6, 14 }, { 8, 16 }, DEG_90  },
                    Zone { Zone::STAGE, { 9, 5 }, { 9, 12 }, DEG_0 }
            },
            { 10, 18 }
    };

    Event event(location, "Concert");
    event.setPrice('A', 100);
    event.setPrice('B', 80);
    event.setPrice('C', 100);
    event.reserveSeat("A26");
    event.reserveSeat("B09");
    event.reserveSeat("C09");

    std::cout << event << "Buy a ticket\n";

    Ticket ticket(event);
//    std::cin >> ticket;

    return 0;
}
