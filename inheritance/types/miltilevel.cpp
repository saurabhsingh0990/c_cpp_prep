#include <iostream>
#include <string>
using namespace std;

/*
    🌟 MULTILEVEL INHERITANCE
    - A class is derived from another derived class.
    - Forms a "chain" of inheritance.
    - Syntax: Base -> Intermediate -> Derived
    - Used when a hierarchy of features is required.
*/


/*
📌 REVISION NOTES:
1. Multilevel inheritance creates a chain — each derived class inherits features of its parent.
2. Constructors are called from base to derived.
3. Destructors are called in reverse order (derived to base).
4. Access specifier 'protected' allows derived classes to access members, but not outside classes.

💡 INTERVIEW TIPS:
- Be ready to explain the **constructor/destructor calling order**.
- If a base class has a **parameterized constructor**, you MUST call it explicitly from the derived class.
- Beware of the "Diamond Problem" → occurs with multiple inheritance (not multilevel).
- Always keep hierarchy logical — don't force inheritance if "is-a" relationship is weak.
*/

// Base class (Level 1)
class Device {
protected:
    string brand;
public:
    Device(string b) : brand(b) {
        cout << "Device constructed for brand: " << brand << endl;
    }
    void showBrand() {
        cout << "Brand: " << brand << endl;
    }
    ~Device() {
        cout << "Device destroyed\n";
    }
};

// Derived class (Level 2)
class Smartphone : public Device {
protected:
    string os;
public:
    Smartphone(string b, string operatingSystem) : Device(b), os(operatingSystem) {
        cout << "Smartphone constructed with OS: " << os << endl;
    }
    void showOS() {
        cout << "Operating System: " << os << endl;
    }
    ~Smartphone() {
        cout << "Smartphone destroyed\n";
    }
};

// Derived class from Smartphone (Level 3)
class FlagshipPhone : public Smartphone {
    int cameraMP;
public:
    FlagshipPhone(string b, string operatingSystem, int mp)
        : Smartphone(b, operatingSystem), cameraMP(mp) {
        cout << "Flagship Phone constructed with " << cameraMP << "MP camera\n";
    }
    void showSpecs() {
        showBrand();
        showOS();
        cout << "Camera: " << cameraMP << "MP\n";
    }
    ~FlagshipPhone() {
        cout << "Flagship Phone destroyed\n";
    }
};

int main() {
    /*
        Real world analogy:
        Device   → General category (like any electronic device)
        Smartphone → Specific device type with OS
        FlagshipPhone → Premium smartphone with high-end features
    */

    FlagshipPhone phone("Samsung", "Android", 200);
    cout << "\n--- Specifications ---\n";
    phone.showSpecs();

    return 0;
}

