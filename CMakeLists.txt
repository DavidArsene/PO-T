cmake_minimum_required(VERSION 3.26)
project(PO_T)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(PO_T
        main.cpp
        Location.cpp
        Location.h
        Zone.cpp
        Zone.h
        Event.cpp
        Event.h
        Ticket.cpp
        Ticket.h)
