#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_AGE = 1, MAX_AGE = 20, NAME_COUNT = 15, COLOR_COUNT = 15;
string names[NAME_COUNT] = {"Billy", "Nanny", "Gruff", "Daisy", "Shadow", "Rocky", "Butters", "Bucky", "Sunny", "Storm", "Blaze", "Midnight", "Misty", "Luna", "Chloe"};
string colors[COLOR_COUNT] = {"Black", "White", "Brown", "Grey", "Spotted", "Yellow", "Blue", "Green", "Red", "Purple", "Pink", "Orange", "Gold", "Silver", "Mauve"};

class Goat {
public:
    int age;
    string name;
    string color;
