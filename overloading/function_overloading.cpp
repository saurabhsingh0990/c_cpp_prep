#include <iostream>
#define PI 3.14
using namespace std;
// Polymorphism
// Function overloading: same function name, different parameter list

// 1. Area of square (one int)
int area(int side) {
    return side * side;
}

// 2. Area of rectangle (two ints)
int area(int length, int width) {
    return length * width;
}

// 3. Area of circle (one double)
double area(double radius) {
    return PI * radius * radius;
}

// 4. Area with mixed types (double and int)
double area(double base, int height) {
    return 0.5 * base * height;  // assuming triangle for variation
}

int main() {
    cout << "Area of square with side 5: " << area(5) << endl;            // calls area(int)
    cout << "Area of rectangle (10 x 5): " << area(10, 5) << endl;        // calls area(int, int)
    cout << "Area of circle with radius 6.5: " << area(6.5) << endl;      // calls area(double)
    cout << "Area of triangle (base 5.5, height 3): " << area(5.5, 3) << endl; // calls area(double, int)

    // Invalid overloads (commented for learning):
    // int area(int x) and int area(int y) --> invalid: only parameter name differs
    // int area(int* p) and int area(int[]) --> invalid: pointer vs array doesn't matter in overloading
    // int area(int a) and int area(const int a) --> invalid: const qualifier doesn't affect overloading

    return 0;
}
