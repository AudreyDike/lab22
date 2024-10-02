#include <iostream>
#include <iomanip> 

class Color {
private:
    int red;    // Red value
    int green;  // Green value
    int blue;   // Blue value

public:
    // Default constructor
    Color() : red(0), green(0), blue(0) {
        cout << "Default constructor called!" << endl;
    }

    // Full parameter constructor
    Color(int r, int g, int b) : red(r), green(g), blue(b) {
        cout << "Full parameter constructor called!" << endl;
    }

    // Partial constructor (sets red, defaults green and blue to 0)
    Color(int r) : red(r), green(0), blue(0) {
        cout << "Partial constructor called!" << endl;
    }

    // Setter functions
    void setRed(int r) {
        red = r;
    }

    void setGreen(int g) {
        green = g;
    }

    void setBlue(int b) {
        blue = b;
    }

    // Getter functions
    int getRed() const {
        return red;
    }

    int getGreen() const {
        return green;
    }

    int getBlue() const {
        return blue;
    }

    // Method to print the color values
    void print() const {
        cout << "Color(R: " << setw(3) << setfill(' ') << red
             << ", G: " << setw(3) << setfill(' ') << green
             << ", B: " << setw(3) << setfill(' ') << blue << ")" << endl;
    }
};

int main() {
    // Instantiate using the default constructor
    Color color1;  // Default color (0, 0, 0)

    // Instantiate using the full parameter constructor
    Color color2(255, 0, 0);  // Red

    // Instantiate using the partial constructor
    Color color3(128);  // Red value only, Green and Blue default to 0

    // Output their values
    cout << "Color Values:" << endl;
    color1.print();  // Default constructor output
    color2.print();  // Full parameter constructor output
    color3.print();  // Partial constructor output

    // Modify color1 using setter methods
    color1.setRed(100);
    color1.setGreen(150);
    color1.setBlue(200);
    color1.print();  // Outputs modified values of color1

    return 0;
}
