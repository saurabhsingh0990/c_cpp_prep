#include <iostream>
#include <string>

/*
    ================= NOTES: Single Inheritance in C++ =================
    - Single Inheritance: A derived class inherits from ONLY ONE base class.
    - This is the simplest form of inheritance and forms a parent-child relationship.
    - Access Specifiers and Inheritance Modes:
        - public inheritance  : public → public, protected → protected in derived.
        - protected inheritance: public & protected → protected in derived.
        - private inheritance  : public & protected → private in derived.
    - Interview Tip: 
        1. Always initialize base class data members using the initializer list in derived class constructors.
        2. Base class constructor is called before derived class constructor.
        3. Order of destruction is reverse: derived destructor → base destructor.
        4. If base class has NO default constructor, derived must explicitly call a parameterized constructor.
    - Real-world example:
        Vehicle (generic properties like speed, company) → Car (adds specific features like seat belts).
*/

class Vehicle {
public:
    std::string company;
    int speed;

    // Parameterized constructor to initialize members
    Vehicle(std::string company, int speed) : company(company), speed(speed) {}

    void printVehicle() {
        std::cout << "Brand : " << company 
                  << " speed : " << speed << " km/hr" 
                  << std::endl;
    }
};

// Derived class: Car inherits from Vehicle using PUBLIC inheritance
class Car : public Vehicle {
private:
    int seatBelt; // Feature specific to Car
public:
    // Constructor that directly initializes base and derived members
    Car(std::string brand, int speed, int seatBelt) 
        : Vehicle(brand, speed), seatBelt(seatBelt) {}

    // Constructor that upgrades an existing Vehicle object into a Car
    Car(const Vehicle& obj, int seatBelt) 
        : Vehicle(obj.company, obj.speed), seatBelt(seatBelt) {}

    void printCar() {
        // Can access `company` and `speed` because of public inheritance
        std::cout << "Brand : " << company 
                  << " speed : " << speed << " km/hr"
                  << " seat belt provided : " << seatBelt 
                  << std::endl;
    }
};

int main() {
    // Creating a generic Vehicle
    Vehicle myVehicle("Honda", 200);
    myVehicle.printVehicle();

    // Upgrading a Vehicle to a Car
    Car myCar_vehicle(std::move(myVehicle), 8);
    myCar_vehicle.printCar();

    // Directly creating a Car
    Car myCar("Toyota", 180, 4);
    myCar.printVehicle(); // Inherited function from Vehicle
    myCar.printCar();     // Function specific to Car

    return 0;
}
