#include <iostream>

#include "Location.h"
#include "Event.h"

int main() {
    Location location {
            "Ateneul Roman",
            std::vector<Zone> {
                    Zone{'A', { 1, 4 }, { 5, 13 }, HORIZONTAL},
                    Zone{'B', { 6, 1 }, { 8, 3 }, VERTICAL},
                    Zone{'C', { 6, 14 }, { 8, 16 }, VERTICAL}
            },
            10,
            18
    };

    Event event(location, "Concert");
    event.setPrice('A', 100);
    event.setPrice('B', 80);
    event.setPrice('C', 100);
    event.reserveSeat("A26");
    event.reserveSeat("B09");
    event.reserveSeat("C09");

    std::cout << event;

    return 0;
}
