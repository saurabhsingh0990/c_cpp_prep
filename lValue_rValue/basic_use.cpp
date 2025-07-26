#include <iostream>
using namespace std;

/*
    Understanding Lvalue and Rvalue in C++

    📌 Why is this important?
    - It forms the basis of move semantics (efficient resource transfers).
    - Helps write better constructors, assignment operators, and function overloads.

    📌 Definitions:
    - **Lvalue** (locator value): 
        - An object that occupies an identifiable memory location.
        - Can appear on the left-hand side of `=`.
        - Example: variables, array elements, dereferenced pointers, etc.
        - Syntax: accessed with <datatype>& (non-const or const).

    - **Rvalue** (read value):
        - Temporary value that doesn't persist beyond the expression.
        - Cannot be assigned to directly.
        - Example: literals, temporary objects, expressions like `a + b`.
        - Syntax: accessed with <datatype>&& (rvalue reference).
        
    📌 Note:
    - `const <datatype>&` can bind to both lvalues and rvalues.
      This allows functions to accept both kinds of values without needing overloads.
*/

// Overloaded PrintName function for lvalue reference
void PrintName(string& name) {
    cout << "Lvalue: " << name << endl;
}

// Overloaded PrintName function for rvalue reference
void PrintName(string&& name) {
    cout << "Rvalue: " << name << endl;
}

int main() {
    string firstName = "Saurabh";  // Lvalue
    string lastName = "Singh";     // Lvalue

    // Concatenation creates a temporary object -> Rvalue
    string fullName = firstName + " " + lastName;

    // Call with lvalue → binds to PrintName(string&)
    PrintName(fullName);

    // Call with rvalue (temporary result of concatenation) → binds to PrintName(string&&)
    PrintName(firstName + lastName);

    return 0;
}
