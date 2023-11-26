#include <iostream>

#include "Location.h"
#include "Event.h"
#include "Ticket.h"

int main() {
//    Location location {
//            "Ateneul Roman",
//            std::vector<Zone> {
//                    Zone { 'A', { 1, 4  }, { 5, 13 }, DEG_180 },
//                    Zone { 'B', { 6, 1  }, { 8, 3  }, DEG_270 },
//                    Zone { 'C', { 6, 14 }, { 8, 16 }, DEG_90  },
//                    Zone { Zone::STAGE, { 9, 5 }, { 9, 12 }, DEG_0 }
//            },
//            { 10, 18 }
//    };

    while (true) {
        std::cout << "What do you want to do?\n"
                     "1. Add location\n"
                     "2. Add event\n"
                     "3. Buy ticket\n"
                     "4. Exit\n";
        int choice = Util::choose(4);

        switch (choice) {
            case 0: {
                Location location;
                std::cin >> location;
                Location::locations.push_back(location);
                break;
            }
            case 1: {
                Event event;
                std::cin >> event;
                Event::events.push_back(event);
                break;
            }
            case 2: {
                Ticket ticket;
                std::cin >> ticket;
                break;
            }
            default: return 0;
        }
    }

    /*
    Location location;
    std::cin >> location;

    Event event(location, "Concert");
    event.setPrice('A', 100);
    event.setPrice('B', 80);
    event.setPrice('C', 100);
    event.reserveSeat("A26");
    event.reserveSeat("B09");
    event.reserveSeat("C09");
    */
}
