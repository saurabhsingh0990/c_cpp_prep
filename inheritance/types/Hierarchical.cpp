#include<iostream>

/*
    Hierarchical Inheritance:
    -------------------------
    - One base class is inherited by multiple derived classes.
    - Useful when you want common properties/behaviors in a base class,
      but each derived class extends it with its own unique features.
    - Interview Tip: Different from multiple inheritance (one class inherits from many)
      and multilevel inheritance (inheritance happens in a chain).
    
    In this program:
    - 'vehicle' is the base class.
    - 'car', 'bike', and 'truck' are derived classes.
    - Each derived class adds its own specific property (seatBelt, helmet, loadCapacity).
    - This demonstrates hierarchical inheritance.
*/

class vehicle {
    private:
        std::string company;
        int speed;
    public:
        // Constructor initializes company and speed
        vehicle(std::string company, int speed){
            this->company = company;
            this->speed = speed;
        }
        // Common function for all derived classes
        void printVehicle(){
            std::cout<<"Brand : "<<company<<" speed : "<<speed<<" km/hr"<<std::endl;
        }
};

// Derived class 1
class car: public vehicle {
    private:
        int seatBelt;
    public:
        // Constructor: initializes base + its own property
        car(std::string brand, int speed, int seatBelt): vehicle(brand, speed){
            this->seatBelt = seatBelt;
        }
        void printCar(){
            // Using base class function
            printVehicle();
            std::cout<<"Seat belts : "<<seatBelt<<std::endl;
        }
};

// Derived class 2
class bike: public vehicle {
    private:
        bool helmet;
    public:
        bike(std::string brand, int speed, bool helmet): vehicle(brand, speed){
            this->helmet = helmet;
        }
        void printBike(){
            printVehicle();
            std::cout<<"Helmet : "<<(helmet ? "Yes" : "No")<<std::endl;
        }
};

// Derived class 3
class truck: public vehicle {
    private:
        int loadCapacity;
    public:
        truck(std::string brand, int speed, int loadCapacity): vehicle(brand, speed){
            this->loadCapacity = loadCapacity;
        }
        void printTruck(){
            printVehicle();
            std::cout<<"Load Capacity : "<<loadCapacity<<" tons"<<std::endl;
        }
};

int main(){
    // Objects of each derived class
    car c("BMW", 240, 5);
    bike b("Yamaha", 180, true);
    truck t("Volvo", 120, 20);

    // Demonstrating hierarchical inheritance in action
    c.printCar();
    std::cout<<std::endl;
    b.printBike();
    std::cout<<std::endl;
    t.printTruck();

    return 0;
}

/*
    Interview Notes:
    ----------------
    Q: What is Hierarchical Inheritance?
    A: When multiple classes inherit from a single base class.

    Q: Example in real life?
    A: "Vehicle" as base, "Car", "Bike", "Truck" as derived.

    Q: Why useful?
    A: Promotes code reusability (common properties in base), 
       and extensibility (each derived can add specific features).
*/
