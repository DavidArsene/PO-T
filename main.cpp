#include <iostream>

#include "Location.h"
#include "Event.h"

int main() {
    Location location(
            "Ateneul Roman",
            new Zone[3] {
                    Zone { 'A', 1, 5, 4, 13, HORIZONTAL },
                    Zone { 'B', 6, 8, 1, 3, HORIZONTAL },
                    Zone { 'C', 6, 8, 14, 16, HORIZONTAL }
            },
            3,
            10,
            18
    );

    Event event(location, "Concert");
    event.reserveSeat(5, 5);
    event.reserveSeat(5, 6);
    event.reserveSeat(5, 7);
    std::cout << event << std::endl;
    return 0;
}
