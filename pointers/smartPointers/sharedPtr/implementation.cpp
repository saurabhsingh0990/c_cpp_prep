
#include <iostream>
#include <cassert>
// Constructor:	Allocates and initializes a raw pointer.
// Copy Constructor:	Shares ownership by copying and incrementing reference count.
// Destructor:	Decrements reference count, deletes object when count reaches zero.
// Assignment Operator:	Handles copy assignment with proper reference count management.
// Dereference (*): To access the managed object.
// Member Access (->) Operators:	To access the managed object.
// get(): Returns the raw pointer.
// use_count():	Returns how many SharedPtrs share ownership.
// reset():	Releases ownership and optionally points to a new object.
// swap():	Exchanges the contents of two SharedPtrs.
// unique():	Checks if this is the only SharedPtr owning the object.

using namespace std;



template <typename T>
class SharedPtr {
    T* data;
    int* ref_count;

public:
    SharedPtr() : data(nullptr), ref_count(nullptr) {}

    explicit SharedPtr(T* val) : data(val), ref_count(new int(1)) {}

    SharedPtr(const SharedPtr& obj) {
        data = obj.data;
        ref_count = obj.ref_count;
        if (ref_count)
            ++(*ref_count);
    }

    SharedPtr& operator=(const SharedPtr& obj) {
        if (this == &obj)
            return *this;

        // Release current resource
        release();

        // Copy new resource
        data = obj.data;
        ref_count = obj.ref_count;
        if (ref_count)
            ++(*ref_count);

        return *this;
    }

    void reset() {
        release();
        data = nullptr;
        ref_count = nullptr;
    }

    void reset(T* val) {
        release();
        data = val;
        ref_count = new int(1);
    }

    T& operator*() const {
        if (!data)
            throw std::runtime_error("Dereferencing null SharedPtr");
        return *data;
    }

    T* operator->() const {
        return data;
    }

    int use_count() const {
        return ref_count ? *ref_count : 0;
    }

    bool unique() const {
        return use_count() == 1;
    }

    T* get() const {
        return data;
    }

    void swap(SharedPtr& other) {
        std::swap(data, other.data);
        std::swap(ref_count, other.ref_count);
    }

    ~SharedPtr() {
        release();
    }

private:
    void release() {
        if (ref_count) {
            --(*ref_count);
            if (*ref_count == 0) {
                delete data;
                delete ref_count;
            }
        }
    }
};


int main() {
    SharedPtr<int> a(new int(100));
    std::cout << "a.use_count(): " << a.use_count() << "\n";  // 1

    SharedPtr<int> b = a;  // Shared ownership
    std::cout << "After b = a\n";
    std::cout << "a.use_count(): " << a.use_count() << "\n";  // 2
    std::cout << "b.use_count(): " << b.use_count() << "\n";  // 2
    std::cout << "*a: " << *a << ", *b: " << *b << "\n";

    SharedPtr<int> c(new int(42));
    std::cout << "c.use_count(): " << c.use_count() << "\n";  // 1

    c = a;  // c now shares with a & b
    std::cout << "After c = a\n";
    std::cout << "a.use_count(): " << a.use_count() << "\n";  // 3
    std::cout << "c.use_count(): " << c.use_count() << "\n";  // 3

    b.reset();  // b no longer points to anything
    std::cout << "After b.reset()\n";
    std::cout << "a.use_count(): " << a.use_count() << "\n";  // 2
    std::cout << "b.use_count(): " << b.use_count() << "\n";  // 0

    c.reset(new int(7));  // c now owns a new int
    std::cout << "After c.reset(new int(7))\n";
    std::cout << "c.use_count(): " << c.use_count() << "\n";  // 1
    std::cout << "*c: " << *c << "\n";

    std::cout << "End of main()\n";
    return 0;
}
