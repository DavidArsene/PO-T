#include <iostream>

#include "Location.cpp"

int main() {
    Location location(
            new Zone[3] {
                    Zone { 'A', 1, 5, 4, 13, HORIZONTAL },
                    Zone { 'B', 6, 8, 1, 3, HORIZONTAL },
                    Zone { 'C', 6, 8, 14, 16, HORIZONTAL }
            },
            3,
            10,
            18
    );
    std::cout << location << std::endl;
    return 0;
}
