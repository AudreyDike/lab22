#include <iostream>
#include <iomanip> // For std::setw and std::setfill
using namespace std;

class Color {
private:
    int red;    // Red value
    int green;  // Green value
    int blue;   // Blue value

public:
    // Default constructor
    Color(int r = 0, int g = 0, int b = 0) : red(r), green(g), blue(b) {}

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
    // Color objects
    Color color1(255, 0, 0);  // Red
    Color color2(0, 255, 0);  // Green
    Color color3(0, 0, 255);  // Blue
    Color color4(255, 255, 0); // Yellow

    // Output their values 
    cout << "Color Values:" << endl;
    color1.print();
    color2.print();
    color3.print();
    color4.print();

    
    Color color5;
    color5.setRed(100);
    color5.setGreen(150);
    color5.setBlue(200);
    color5.print();  // Outputs the values of color5

    return 0;
}

