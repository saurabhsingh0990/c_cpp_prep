#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int image;

public:
    // Default constructor: initializes complex number to 0 + 0i
    Complex() : real(0), image(0) {}

    // Parameterized constructor: initializes with given real and imaginary parts
    Complex(int r, int i) : real(r), image(i) {}

    // Binary operator overloading: Complex + Complex
    Complex operator+(Complex obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.image = image + obj.image;
        return temp;
    }

    // Binary operator overloading: Complex - Complex
    Complex operator-(Complex obj) {
        Complex temp;
        temp.real = real - obj.real;
        temp.image = image - obj.image;
        return temp;
    }

    // Overload == to compare two complex numbers
    bool operator==(Complex obj) {
        return (real == obj.real && image == obj.image);
    }

    // Utility function to print complex number
    void print() {
        cout << real << " + " << image << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3);     // Create complex number 2 + 3i
    c1.print();

    Complex c2(5, 3);     // Create complex number 5 + 3i
    c2.print();

    Complex c3 = c1 + c2; // c3 = c1 + c2 = (7 + 6i)
    c3.print();

    Complex c4 = c2 - c1; // c4 = c2 - c1 = (3 + 0i)
    c4.print();

    // Comparing c3 and c4 using overloaded ==
    if (c3 == c4)
        cout << "equal";
    else
        cout << "not equal";

    return 0;
}
