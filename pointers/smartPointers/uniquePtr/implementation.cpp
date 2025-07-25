#include <iostream>
#include <utility>  // for std::move

using namespace std;

// Custom implementation of a simplified std::unique_ptr
template<typename T>
class Unique_ptr {
private:
    T* res; // raw pointer to manage the resource

public:
    // Constructor - takes ownership of a raw pointer
    explicit Unique_ptr(T* a = nullptr) : res(a) {
        cout << "constructor called" << endl;
    }

    // Disable copy constructor - unique_ptr cannot be copied
    Unique_ptr(const Unique_ptr<T>&) = delete;

    // Disable copy assignment operator - unique_ptr cannot be copied
    Unique_ptr& operator=(const Unique_ptr<T>&) = delete;

    // Move constructor - transfers ownership from another unique_ptr
    Unique_ptr(Unique_ptr<T>&& ptr) {
        res = ptr.res;
        ptr.res = nullptr;
    }

    // Move assignment operator - transfers ownership from another unique_ptr
    Unique_ptr& operator=(Unique_ptr<T>&& ptr) {
        // Guard self-assignment
        if (this != &ptr) {
            // Delete existing resource if any
            if (res)
                delete res;

            // Transfer ownership
            res = ptr.res;
            ptr.res = nullptr;
        }
        return *this;
    }

    // Overload arrow operator to access members of the resource
    T* operator->() {
        return res;
    }

    // Overload dereference operator to get the actual value
    T& operator*() {
        return *res;
    }

    // Returns the raw pointer
    T* get() {
        return res;
    }

    // Resets the managed resource to a new one (optional)
    void reset(T* newres = nullptr) {
        if (res)
            delete res; // Clean up existing resource
        res = newres;   // Take ownership of new resource
    }

    // Destructor - deletes the managed resource
    ~Unique_ptr() {
        if (res) {
            delete res;
            res = nullptr;
        }
    }
};

int main() {
    // Create unique pointer managing dynamic int with value 2
    Unique_ptr<int> ptr1(new int(2));

    // Create another unique pointer managing int(500)
    Unique_ptr<int> ptr3(new int(500));

    // Move ownership from ptr1 to ptr3 (ptr1 becomes null)
    ptr3 = std::move(ptr1);

    // Now move ownership back from ptr3 to ptr1
    ptr1 = std::move(ptr3);

    // Check if ptr1 holds a resource and print it
    if (ptr1.get())
        cout << *ptr1 << endl;

    // Reset ptr1 to manage a new int(30)
    ptr1.reset(new int(30));
    cout << *ptr1 << endl;

    // Destructor will automatically be called for ptr1 and ptr3
    return 0;
}
