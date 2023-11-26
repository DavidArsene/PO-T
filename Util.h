#pragma once

#include <iostream>
#include <functional>
#include <numeric>
#include "termcolor.hpp"

class Util {
public:

    template<typename T>
    static T input(std::string_view prompt,
                   const std::function<void (const T&)>& validator = [](const T &) { }
    ) {
        T value;
        do {
            std::cout << prompt;
            try {
                if constexpr (std::is_same_v<T, std::string>) {
                    std::cin.ignore();
                    std::getline(std::cin, value);
                } else std::cin >> value;

                validator(value);
                return value;
            } catch (std::invalid_argument& e) {
                std::cout << termcolor::red << e.what() << termcolor::reset << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);
    }

    static int choose(int size) {
        return input<int>("Choice: ", [&size](auto choice) {
            if (choice < 1 || choice >= size + 1)
                throw std::invalid_argument("Invalid choice");
        }) - 1;
    }
};
