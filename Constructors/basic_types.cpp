#include <iostream>
// This demonstrates basic constructor concepts:
//
// default constructor: No parameters
// parameterized constructor: Takes an int pointer
// copy constructor: Makes a copy of an object
// move constructor: Transfers ownership from a temporary
// copy assignment operator: copy object via assignment
// move assignment operator: Transfers ownership via assignment

using namespace std;

class Int {
private:
    int* num;

public:
    // Default constructor
    Int() : num(nullptr) {
        cout << "Default constructor\n";
    }

    // Parameterized constructor
    // This is called a delegating or member initializer list constructor
    Int(int* data) : num(data) {
        cout << "Parameterized constructor\n";
    }

    // Copy constructor (takes const reference to allow rvalues & lvalues)
    Int(const Int& obj) {
        cout << "Copy constructor\n";
        if (obj.num)
            num = obj.num; 
        else
            num = nullptr;
    }
    // copy assignment operator
    Int&  operator= (const Int& obj){
        cout << "Copy assignment opertor\n";
        if(obj.num){
            num = obj.num;
        }else{
            num = nullptr;
        }
        return *this;
    }

    // Move constructor
    Int(Int&& obj) {
        cout << "Move constructor\n";
        num = obj.num;
        obj.num = nullptr;
    }

    // Move assignment operator
    Int& operator=(Int&& obj) noexcept {
        cout << "Move assignment operator\n";
        if (this != &obj) {
            delete num;  // Free existing
            num = obj.num;
            obj.num = nullptr;
        }
        return *this;
    }

    // Getter
    Int& get() {
        return *this;
    }

    void print() {
        if (num)
            cout << *num << endl;
        else
            cout << "null" << endl;
    }

    // Destructor to clean memory
    ~Int() {
        delete num;
    }
};

int main() {
    Int num(new int(10));   // Parameterized constructor
    Int num1(num);          // Copy constructor
    Int num2 = move(num1);  // Move constructor

    Int num3;               // Default constructor
    num3 = move(num);       // Move assignment operator

    cout << "Value inside num1: ";
    num1.print();           // Should be null
    cout << "Value inside num3: ";
    num3.print();           // Should show 10
    Int num4;
    num4 = num3;
    cout << ("value inside num4 : ");
    num4.print();
    return 0;
}
