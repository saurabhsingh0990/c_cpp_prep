#include <iostream>

// Storage Class Summary:
// Type      | Storage      | Default Value | Scope         | Lifetime
// --------------------------------------------------------------------
// auto      | Stack        | Garbage       | Local (block) | End of block
// static    | Data Segment | Zero          | Local/Global  | End of program
// extern    | Data Segment | Zero          | Global        | End of program
// register  | CPU Register | Garbage       | Local (block) | End of block
//
// Note: Modern compilers often ignore `register` and optimize automatically.

using namespace std;

// extern variable declared
extern int globalCounter;

void counter() {
    static int count = 0; // Initialized only once
    count += 1;
    cout << "Function called " << count << " times!" << endl;
}

int globalCounter = 5; // Definition of extern variable

int main() {
    // auto variable (default in modern C++)
    {
        auto a = 10;
        cout << "Auto variable inside scope: " << a << endl;
    }

    cout << "\nUsing static variable:\n";
    counter();
    counter();

    cout << "\nUsing extern variable (defined globally): ";
    cout << globalCounter << endl;

    cout << "\nUsing register variable:\n";
    // ISO C++17 does not allow 'register' storage class specifier (deprecated)
    // register int b = 20; // Hint to store in CPU register
    // cout << "Register variable value: " << b << endl;

    return 0;
}
