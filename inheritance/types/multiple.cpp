#include <iostream>
#include <string>
using namespace std;

/*
📝 Interview Revision Notes on Multiple Inheritance

Definition: A class can inherit from more than one base class.

class Derived : public Base1, public Base2 { ... };

Real-world analogy: A Smartphone is both a CommunicationDevice and an EntertainmentDevice.

Constructor order:

Base class constructors are called in the order they are inherited.
→ class Smartphone : public CommunicationDevice, public EntertainmentDevice
→ CommunicationDevice → EntertainmentDevice → Smartphone

Destructor order:

Opposite of construction order (Derived → Base2 → Base1).

Diamond Problem:

If both base classes inherit from a common class, ambiguity occurs (which copy should be used?).

Resolved using Virtual Inheritance.

Method Ambiguity:

If both base classes have a method with the same name, you must specify which one:
obj.Base1::method(); or obj.Base2::method();

🎯 Interview Tips

Be ready to explain with a real-world analogy (Smartphone, Car = Vehicle + Machine, etc.).

Know the constructor/destructor order → very common MCQ/Interview Q.

If asked about problems with multiple inheritance → mention:

Diamond Problem

Method Ambiguity

Increased complexity in maintenance.

Know Virtual Inheritance keywords (virtual before base classes) to solve diamond problem.
*/

// Base Class 1: Communication Device
class CommunicationDevice {
public:
    CommunicationDevice() {
        cout << "CommunicationDevice constructed ✅" << endl;
    }

    void makeCall(string number) {
        cout << "Calling " << number << "..." << endl;
    }

    ~CommunicationDevice() {
        cout << "CommunicationDevice destroyed ❌" << endl;
    }
};

// Base Class 2: Entertainment Device
class EntertainmentDevice {
public:
    EntertainmentDevice() {
        cout << "EntertainmentDevice constructed ✅" << endl;
    }

    void playMusic(string song) {
        cout << "Playing song: " << song << endl;
    }

    ~EntertainmentDevice() {
        cout << "EntertainmentDevice destroyed ❌" << endl;
    }
};

// Derived Class: Smartphone inherits from BOTH
class Smartphone : public CommunicationDevice, public EntertainmentDevice {
public:
    Smartphone() {
        cout << "Smartphone constructed 📱" << endl;
    }

    void browseInternet(string website) {
        cout << "Browsing: " << website << endl;
    }

    ~Smartphone() {
        cout << "Smartphone destroyed ❌" << endl;
    }
};

int main() {
    Smartphone s; // When object is created → constructors of BOTH base classes are called first
    cout << endl;

    // Now Smartphone has features of BOTH base classes:
    s.makeCall("+91-9876543210");  
    s.playMusic("Coldplay - Yellow");  
    s.browseInternet("www.openai.com");  

    cout << endl;
    return 0;
}
