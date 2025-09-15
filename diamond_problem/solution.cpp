#include<iostream>
using namespace std;

// 🔹 Diamond Problem Example with Virtual Inheritance
// Key Interview Qs:
// 1. What is the Diamond Problem?
//    - Ambiguity arises when a class is inherited multiple times through different paths.
//    - E.g., A → B and A → C, and then D inherits from both B & C.
//    - Without virtual inheritance, D would get TWO copies of A (ambiguity).
//
// 2. How does virtual inheritance solve it?
//    - With 'virtual', only ONE shared instance of A exists in D.
//    - This removes ambiguity for A’s members.

// ---------------- Base Class ----------------
class A {
public:
    int x;
    A() {
        x = 10;
        cout << "A's constructor called, x = " << x << endl;
    }
};

// ---------------- Derived Class B ----------------
// Inherits A virtually → ensures only one copy of A exists when combined with other classes
class B : virtual public A {
public:
    int y;
    B() {
        x = 15;   // modifies the SINGLE shared 'x' from A
        y = 20;
        cout << "B's constructor called, y = " << y << endl;
    }
};

// ---------------- Derived Class C ----------------
class C : virtual public A {
public:
    int z;
    C() {
        x = 25;   // modifies the SAME 'x' from A (not a new copy)
        z = 30;
        cout << "C's constructor called, z = " << z << endl;
    }
};

// ---------------- Most Derived Class D ----------------
// Inherits both B and C → Diamond Problem resolved with virtual inheritance
class D : public B, public C {
public:
    int sum;
    D() {
        // ✅ Only one 'x' exists → no ambiguity
        sum = x + y + z; 
        cout << "D's constructor called, sum = " << sum << endl;
    }
    void show() {
        cout << "A::x = " << x << endl; // refers to the single 'x' from A
        cout << "y = " << y << ", z = " << z << endl;
        cout << "Sum = " << sum << endl;
    }
};

// ---------------- Main ----------------
int main() {
    D obj;   // When obj is created:
// Order of constructor calls:
//   A → B → C → D   (Virtual base A constructed only ONCE)
//
// Interview Tip: Most derived class (D) controls construction of virtual base (A).
// If A had parameters, D would be responsible for initializing it.

    obj.show();
    return 0;
}
