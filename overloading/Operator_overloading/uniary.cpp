#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Display coordinates
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // Unary minus (-): Flips signs of both x and y
    Point operator-() const {
        return Point(-x, -y);
    }

    // Prefix increment (++obj): Increments both x and y
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }
};

int main() {
    Point p1(2, -3);

    cout << "Original point: ";
    p1.display();

    // Unary minus
    Point p2 = -p1; // Calls operator-()
    cout << "After applying unary minus: ";
    p2.display();

    // Prefix increment
    ++p1; // Calls operator++()
    cout << "After prefix increment (++p1): ";
    p1.display();

    return 0;
}
