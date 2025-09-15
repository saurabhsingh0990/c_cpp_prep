#include<iostream>


/*
    Diamond Problem in C++:
    -----------------------
    - Occurs in multiple inheritance when two derived classes inherit from the same base class,
      and a fourth class inherits from both derived classes.
    - This creates ambiguity because the fourth class has two copies of the base class's properties/methods.
    - To resolve this, C++ provides 'virtual inheritance' which ensures only one copy of the base class is shared.

    In this program:
    - 'A' is the base class.
    - 'B' and 'C' are derived from 'A'.
    - 'D' inherits from both 'B' and 'C'.
    - Without virtual inheritance, 'D' would have two copies of 'A's properties.
    - With virtual inheritance, 'D' has only one shared copy of 'A's properties.
*/
using namespace std;
class A {
    public:
        int x;
        A() {
            x = 10;
            cout << "A's constructor called, x = " << x << endl;
        }
};  
class B :  public A { // inheritance
    public:
        int y;
        B() {
            x = 15; // Modifying A's x
            y = 20;
            cout << "B's constructor called, y = " << y << endl;
        }
};
class C :  public A { // inheritance
    public:
        int z;
        C() {
            x = 25; // Modifying A's x
            z = 30;
            cout << "C's constructor called, z = " << z << endl;
        }
};
class D : public B, public C { // Diamond Problem
    public:
        int sum;
        D() {
            // Ambiguity: Which 'x' to use? B's A or C's A?
            // sum = x + y + z; // This would cause a compilation error
            sum = C::x + y + z; // Resolving ambiguity by specifying the path
            cout << "D's constructor called, sum = " << sum << endl;
        }
        void show() {
            // Accessing x from both B and C
            cout << "B's A::x = " << B::x << endl; // Accessing x from B's A
            cout << "C's A::x = " << C::x << endl; // Accessing x from C's A
            cout << "y = " << y << ", z = " << z << endl;
            cout << "Sum = " << sum << endl;
        }
};
int main() {
    D objD; // Creating object of D
    objD.show(); // Displaying values
    return 0;
}