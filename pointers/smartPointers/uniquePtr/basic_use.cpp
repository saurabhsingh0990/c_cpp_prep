#include <memory>
#include <iostream>
using namespace std;

/*
 * Demonstration of smart pointers and resource management using:
 *  - unique_ptr      : A smart pointer that owns and deletes the resource it holds.
 *  - get()           : Returns the raw pointer inside unique_ptr (does not transfer ownership).
 *  - move()          : Transfers ownership from one unique_ptr to another.
 *  - make_unique     : Safer way to create a unique_ptr (from C++14 onwards).
 *  - reset()         : Deletes the currently held resource and optionally takes a new one.
 *  - release()       : Releases ownership and returns raw pointer (you must delete manually).
 *  - new             : Allocates memory manually on the heap.
 *  - constructor     : Initializes the object.
 *  - destructor      : Cleans up when the object is deleted.
 */

// A simple class to track constructor/destructor behavior
class Resource {
public:
    Resource() {
        cout << "Constructor for Resource" << endl;
    }
    ~Resource() {
        cout << "Destructor for Resource" << endl;
    }
    void foo(string context) {
        cout << "Inside foo (" << context << ")" << endl;
    }
};

void demo() {
    // make_unique: Preferred way to create unique_ptr safely
    unique_ptr<Resource> obj = make_unique<Resource>();
    obj->foo("using make_unique inside demo()");
    // Resource will be automatically deleted when `obj` goes out of scope
}

int main() {
    demo(); // Call demo to test make_unique

    Resource* copy_ptr;                   // Raw pointer (not recommended without smart pointer backup)
    unique_ptr<Resource> uni_ptr_copy;    // Will take ownership using move later

    {
        // new: Allocates resource on heap (no auto cleanup)
        Resource* old_ptr = new Resource();   
        copy_ptr = old_ptr;               // Another raw pointer to the same memory
        old_ptr->foo("raw pointer");

        // unique_ptr: Manages memory automatically (RAII)
        unique_ptr<Resource> ptr1(new Resource);  
        cout << "ptr1 holds: " << ptr1.get() << " (heap allocated)" << endl;
        ptr1->foo("unique_ptr");

        // move(): Transfers ownership (can't copy unique_ptr)
        uni_ptr_copy = move(ptr1);        // uni_ptr_copy now owns the Resource
        cout << "ptr1 now holds: " << ptr1.get() << " (should be nullptr)" << endl;

        ptr1 = nullptr;                   // Optional safety: avoid using a moved-from pointer
    } 
    // Scope ends:
    // - ptr1: goes out of scope, does not delete (ownership was moved)
    // - old_ptr: goes out of scope, but memory leak (no delete)
    
    cout << "After inner scope ends..." << endl;

    uni_ptr_copy->foo("from moved unique_ptr");

    // reset(): Deletes current resource and optionally assigns new one
    uni_ptr_copy.reset(new Resource); // old resource is destroyed, new one created
    cout << "uni_ptr_copy now holds: " << uni_ptr_copy.get() << endl;

    // release(): Gives up ownership without deleting the object
    // NOTE: We must delete manually later to avoid memory leak
    Resource* leaked_ptr = uni_ptr_copy.release(); 
    cout << "After release(), uni_ptr_copy = " << uni_ptr_copy.get() << ", leaked_ptr = " << leaked_ptr << endl;

    // Raw pointer (copy_ptr) still points to Resource created earlier
    copy_ptr->foo("still alive via raw pointer");

    // Cleanup the released resource manually (to avoid leak)
    delete leaked_ptr;

    return 0; 
    // Any remaining unique_ptr will delete their held objects automatically
}
