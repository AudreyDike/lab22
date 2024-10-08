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
    