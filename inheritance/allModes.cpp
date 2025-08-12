#include <iostream>
using namespace std;

/*
📝 NOTES:
Inheritance allows a class (derived) to reuse & extend features of another (base) class.
Modes of inheritance control how base class members are treated in the derived class:

1️⃣ Public Inheritance:
    - public → public
    - protected → protected
    - private → not accessible
    ✔ Use when the derived class "IS-A" type of base class (e.g., Car IS-A Vehicle)

2️⃣ Protected Inheritance:
    - public → protected
    - protected → protected
    - private → not accessible
    ✔ Use when you want to reuse base code but NOT expose it to the outside world.

3️⃣ Private Inheritance (default for `class`):
    - public → private
    - protected → private
    - private → not accessible
    ✔ Use when the derived class "HAS-A" relationship internally using base class features.
*/

// Base Class
class Vehicle {
public:
    
    Vehicle(string b = "Generic Brand") : brand(b) {}

    void showBrand() {
        cout << "Brand: " << brand << endl;
    }
protected:
    int maxSpeed = 100; // Accessible to derived classes but not outside
private:
    string brand;
    string engineSerial = "XYZ123"; // Completely hidden
};

// Public Inheritance Example
class Car : public Vehicle {
public:
    Car(string b, int seats) : Vehicle(b), seatingCapacity(seats) {}
    void showCarDetails() {
        showBrand(); // ✅ allowed (public stays public)
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Max Speed: " << maxSpeed << endl; // ✅ protected stays protected
        // cout << engineSerial; ❌ Not allowed (private in base)
    }
private:
    int seatingCapacity;
};

// Protected Inheritance Example
class Bike : protected Vehicle {
public:
    Bike(string b, bool helmet) : Vehicle(b), helmetIncluded(helmet) {}
    void showBikeDetails() {
        showBrand(); // ✅ still accessible inside derived
        cout << "Helmet Included: " << (helmetIncluded ? "Yes" : "No") << endl;
        cout << "Max Speed: " << maxSpeed << endl; // ✅
    }
    // ❌ Outside world cannot directly call showBrand() on Bike objects
private:
    bool helmetIncluded;
};

// Private Inheritance Example
class ElectricScooter : private Vehicle {
public:
    ElectricScooter(string b, int battery) : Vehicle(b), batteryLife(battery) {}
    void showScooterDetails() {
        showBrand(); // ✅ still usable internally
        cout << "Battery Life: " << batteryLife << " hrs" << endl;
    }
    // ❌ Outside world can't treat ElectricScooter as Vehicle
private:
    int batteryLife;
};

int main() {
    cout << "--- Public Inheritance (Car) ---" << endl;
    Car car("Toyota", 5);
    car.showCarDetails(); // ✅ Works
    car.showBrand();      // ✅ Accessible (public stays public)

    cout << "\n--- Protected Inheritance (Bike) ---" << endl;
    Bike bike("Yamaha", true);
    bike.showBikeDetails(); // ✅ Works
    // bike.showBrand(); ❌ Not accessible here

    cout << "\n--- Private Inheritance (Electric Scooter) ---" << endl;
    ElectricScooter scooter("Xiaomi", 8);
    scooter.showScooterDetails(); // ✅ Works
    // scooter.showBrand(); ❌ Not accessible here

    return 0;
}

/*
💡 REAL-WORLD ANALOGY:
Think of Vehicle as a base design.

- Car (public): Everyone knows it's a Vehicle; you can access Vehicle features directly.
- Bike (protected): Still a Vehicle internally, but you hide that fact from outsiders.
- ElectricScooter (private): Uses Vehicle’s design internally, but doesn't publicly say "I am a Vehicle".
*/
