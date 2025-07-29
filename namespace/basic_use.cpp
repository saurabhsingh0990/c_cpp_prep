#include <iostream>

// Example demonstrating the use of namespaces and different ways to use them
// Quick Revision:
// - What is a namespace?
//   A declarative region to avoid naming conflicts.
// - Why use namespaces?
//   To organize code and prevent name clashes.
// - Ways to use namespaces:
//   1. Entire namespace: using namespace name;
//   2. Scoped usage: name::member
//   3. Specific member: using name::member;
//   4. Namespace extension
// - Which is better?
//   Prefer scoped usage (name::member) for clarity and safety.

using namespace std;

namespace MathUtils {
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }
}

namespace MathUtils { // Namespace extension
    int multiply(int a, int b) {
        return a * b;
    }
}

int main() {
    cout << "-- Using full namespace --" << endl;
    {
        using namespace MathUtils; // brings all members into scope
        cout << "Add: " << add(5, 3) << endl;
        cout << "Subtract: " << subtract(5, 3) << endl;
        cout << "Multiply: " << multiply(5, 3) << endl;
    }

    cout << "\n-- Using scoped access --" << endl;
    {
        cout << "Add: " << MathUtils::add(10, 4) << endl;
    }

    cout << "\n-- Using specific member only --" << endl;
    {
        using MathUtils::subtract;
        cout << "Subtract: " << subtract(9, 2) << endl;
        // cout << multiply(2, 3); // ❌ Not allowed, not in scope
    }

    return 0;
}
