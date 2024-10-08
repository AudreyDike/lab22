#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>  
using namespace std;

const int SIZE = 3;
const int MIN = 10000, MAX = 99999;

class Chair {
private:
    int legs;
    double* prices;

public:
  // Default constructor
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % 2) + 3; // Randomly assign 3 or 4 legs
        for (int i = 0; i < SIZE; i++) {
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double)100; // Random prices between 100 and 999.99
        }
    }

    // Parameter constructor with legs and prices
    Chair(int l, double* p) {  // Accept pointer to array
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }
    }

