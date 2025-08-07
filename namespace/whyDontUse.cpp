#include<iostream>
// using name can create problem while debugging beacuse a developer you wont know which name space was used for which function
// can lead to run time error
//  never use namespace in header files 
// using namespace::func_name() make it easier to track func_name()
// for example vector is present in std and ea_stl namespace if both namespace are used it will be difficult to find vector was called from which naem space

namespace car{
    void drive(){
        std::cout << "car is running"<< std::endl; 
    }
}

namespace scooter{
    void drive(){
        std::cout << "scooter is running" << std::endl;
    }
}

using namespace car;
using namespace scooter;
int main(){
    // drive(); // gives error
    // better way is
    car::drive();
    scooter::drive();
    return 0;
}