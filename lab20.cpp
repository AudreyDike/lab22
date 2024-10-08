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
 // Setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++) {
            cout << prices[i] << " ";  // Fully close the for loop statement
        }
        cout << endl << "Historical avg price: " << getAveragePrices(); 
        cout << endl << endl;
    }

    // Destructor to clean up dynamic memory
    ~Chair() {
        delete[] prices;
    }
};

int main() {
    srand(time(0)); 
    cout << fixed << setprecision(2);

    // Using default constructor with random values
    Chair* chairPtr = new Chair;
    chairPtr->print();
    delete chairPtr;

    // Using parameter constructor with legs and prices array
    double customPrices[SIZE] = { 525.25, 434.34, 252.52 };
    Chair* livingChair = new Chair(3, customPrices);
    livingChair->print();
    delete livingChair;

    // Dynamic array of Chair objects with default constructor
    Chair* collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }
    delete[] collection;  // to delete an array of objects

    return 0;
}
