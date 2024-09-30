// movie.cpp
#include <iostream>
#include "movie.h"

void Movie::setTitle(const std::string &t) {
    title = t;
}

void Movie::setYearReleased(int y) {
    yearReleased = y;
}

void Movie::setScreenwriter(const std::string &s) {
    screenwriter = s;
}

std::string Movie::getTitle() const {
    return title;
}

int Movie::getYearReleased() const {
    return yearReleased;
}

std::string Movie::getScreenwriter() const {
    return screenwriter;
}

void Movie::print() const {
    std::cout << "Movie: " << title << "\n"
              << "    Year released: " << yearReleased << "\n"
              << "    Screenwriter: " << screenwriter << std::endl;
}
