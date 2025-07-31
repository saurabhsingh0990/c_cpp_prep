// RAII stands for Resource Acquisition Is Initialization
// It means the lifetime of a resource is tied to the lifetime of an object
// When object is created → resource is acquired (e.g. heap memory allocated)
// When object is destroyed → resource is released automatically

// Smart pointers like std::unique_ptr and std::shared_ptr use this RAII principle

#include <iostream>
using namespace std;

template <typename T>
class Raii {
private:
    T* ptr; // Raw pointer to dynamically allocated memory

public:
    // Constructor: Acquires the resource
    Raii(T* data = nullptr) : ptr(data) {
        cout << "constructor called" << endl;
        cout << "ptr is created and address is " << get() << endl;
    }

    // Copy constructor deleted
    // Why? Because we don't want two objects owning the same resource (double deletion issue)
    Raii(Raii& obj) = delete;

    // Copy assignment operator deleted
    // Same reason: To avoid ownership duplication
    Raii& operator=(Raii& obj) = delete;

    // Move constructor: Transfers ownership from source object to new object
    Raii(Raii&& obj) {
        if (obj.ptr) {
            this->ptr = obj.ptr;      // Take the resource
            obj.ptr = nullptr;        // Nullify the source
        } else {
            this->ptr = nullptr;
        }
    }

    // Move assignment operator: Transfers ownership and deletes any existing resource
    Raii& operator=(Raii&& obj) {
        if (obj.ptr) {
            delete this->ptr;         // Clean up old resource
            this->ptr = obj.ptr;      // Take over new one
            obj.ptr = nullptr;
        } else {
            this->ptr = nullptr;
        }
        return *this;
    }

    // Getter for pointer address (useful for debugging or inspection)
    T* get() {
        return ptr;
    }

    // Prints the value pointed to, or tells if ptr is null
    void print() {
        if (ptr)
            cout << *ptr << endl;
        else
            cout << "ptr is pointing to null" << endl;
    }

    // Destructor: Releases the resource
    ~Raii() {
        cout << "destructor called" << endl;
        delete ptr;                   // Prevents memory leak
        ptr = nullptr;                // Avoid dangling pointer
        cout << "ptr now points towards null" << endl;
    }
};

// Template print function that accepts an object by reference
// If we passed it by value, the move constructor or deleted copy constructor would be called
// So, using `Raii<T>&` prevents unnecessary moves and avoids copy (which is deleted)
template<typename T>
void print(Raii<T>& obj) {
    cout << "value : ";
    obj.print();
    cout << "it is stored at location " << obj.get() << endl;
}

int main() {
    Raii<int> int1(new int(7));
    cout << "int1 ";
    print(int1);

    // Works with string as well since we templated the class
    Raii<string> name(new string("saurabh"));
    print(name);

    Raii<int> int2;
    cout << "move assignment operator " << endl;
    int2 = move(int1); // Transfers ownership from int1 to int2
    cout << "int2 ";
    print(int2);
    cout << "int1 ";
    print(int1); // Should show null

    cout << "move constructor " << endl;
    Raii<int> int3 = move(int2); // Transfers ownership from int2 to int3
    cout << "int3 ";
    print(int3);
    cout << "int2 ";
    print(int2); // Should show null

    return 0;
}
