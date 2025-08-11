#include <iostream>

// ======================
// 📚 NOTES ON FRIEND CLASS
// ======================
// 1. A friend class can access the private and protected members of the class that declares it as a friend.
// 2. Friendship is *not* mutual. If A is a friend of B, B is NOT automatically a friend of A.
// 3. Friendship is *not* inherited. If class C inherits from A, it does not inherit friendship privileges.
// 4. Common use case: When two classes are closely related, and one needs full access to another’s internals,
//    without making those members public.
//
// 🚗 Real-world analogy:
// Imagine a Vehicle Service Center (Printed class) that needs full access to a car’s internal parts (Vehicle’s private members).
// We don’t want everyone to see these details (public), but the service center is trusted, so it is granted friend access.

// ==================================
// Class that will grant friendship
// ==================================
class Vehicle {
private:
    const char *name;
    int engine;   // engine capacity
    int mileage;  // in km per liter

public:
    int tyre; // public info
    Vehicle(const char *val, int eng, int mil, int ty)
        : name(val), engine(eng), mileage(mil), tyre(ty) {}

    // Declaring Printed as a friend class
    friend class Printed;
};

// ==================================
// A different class (NO friendship here)
// ==================================
class Scooter {
private:
    int color; // private: not accessible to Printed

public:
    int brake; // public info
    Scooter(int col, int bPower) : color(col), brake(bPower) {}
};

// ==================================
// Friend class of Vehicle
// ==================================
class Printed {
public:
    Printed() {}

    // Can access private members of Vehicle because it is a friend
    void printVehicle(const Vehicle &obj) {
        std::cout << "Vehicle Name : " << obj.name
                  << ", Engine capacity: " << obj.engine << "L"
                  << ", Mileage: " << obj.mileage << " km/l"
                  << ", Tyres: " << obj.tyre << std::endl;
    }

    // Cannot access private members of Scooter (will cause compile error if tried)
    void printScooter(const Scooter &obj) {
        // std::cout << "Scooter Color : " << obj.color << std::endl; // ❌ Error: 'color' is private
        std::cout << "Scooter brake power: " << obj.brake << std::endl;
    }
};

// ==================================
// MAIN
// ==================================
int main() {
    Vehicle car("Sedan", 2, 22, 4);
    Printed printer;

    // ✅ Accessing private Vehicle data through friend class
    printer.printVehicle(car);

    // ✅ Accessing only public Scooter data
    Scooter vespa(3, 34);
    printer.printScooter(vespa);

    return 0;
}
