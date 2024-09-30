// movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string title;
    int yearReleased;
    std::string screenwriter;

public:
    void setTitle(const std::string &t);
    void setYearReleased(int y);
    void setScreenwriter(const std::string &s);

    std::string getTitle() const;
    int getYearReleased() const;
    std::string getScreenwriter() const;

    void print() const;
};

#endif
