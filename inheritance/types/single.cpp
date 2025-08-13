#include <iostream>
#include <string>

class Vehicle{
    public:
        std::string company;
        int speed;
        
        Vehicle(std::string company, int speed) : company(company),speed(speed){};  

        void printVehicle(){
            std::cout << "Brand : " << company << " speed : " << speed << " km/hr" << std::endl;
        }
};

class Car: public Vehicle{
    private:
        int seatBelt;
    public:
        Car(std::string brand, int speed, int seatBelt) : Vehicle(brand, speed), seatBelt(seatBelt){};
        Car(const Vehicle& obj, int seatBelt) : Vehicle(obj.company, obj.speed) ,seatBelt(seatBelt){};
        void printCar(){
            std::cout << "Brand : " << company << " speed : " << speed << " km/hr" << " seat belt provided : " << seatBelt<<std::endl;
        }
};

int main(){
    Vehicle myVehicle ("Honda", 200);
    myVehicle.printVehicle();
    
    Car myCar_vehicle(std::move(myVehicle), 8);
    myCar_vehicle.printCar();

    Car myCar ( "Toyota", 180, 4);
    myCar.printVehicle(); // car object can call print from vehicle class because it was inherited publicly 
    myCar.printCar();
    return 0;
}