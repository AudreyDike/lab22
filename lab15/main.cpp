#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "movie.h"

int main() {
    std::vector<Movie> movies;  // Vector to store Movie objects

    std::ifstream inputFile("input.txt");  // Open the input file
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    while (!inputFile.eof()) {
        Movie tempMovie;
        std::string title;
        int yearReleased;
        std::string screenwriter;

        // Read data from file
        std::getline(inputFile, title);
        inputFile >> yearReleased;
        inputFile.ignore(); // Ignore the newline character after the integer
        std::getline(inputFile, screenwriter);

        // Set movie data
        tempMovie.setTitle(title);
        tempMovie.setYearReleased(yearReleased);
        tempMovie.setScreenwriter(screenwriter);

        // Append movie to vector
        movies.push_back(tempMovie);
    }

    inputFile.close();  // Close the file

    // Output the contents of the vector
    for (const Movie &movie : movies) {
        movie.print();
        std::cout << std::endl;  // Print a blank line between movies
    }

    return 0;
}
