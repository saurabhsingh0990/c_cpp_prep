#include <iostream>
#include <memory>  // For shared_ptr
using namespace std;

/*
📌 QUICK REVISION:

🔹 shared_ptr<T> : Smart pointer that allows multiple shared ownerships of a dynamically allocated object.
🔹 make_shared<T>(val) : Creates a shared_ptr (more efficient than using 'new').
🔹 get() : Returns the raw pointer managed by shared_ptr.
🔹 use_count() : Returns number of shared_ptrs managing the same object.
🔹 reset() : Releases ownership from current shared_ptr (decrements reference count).
🔹 unique() : Returns true if use_count() == 1.
🔹 swap(ptrA, ptrB) : Swaps contents of two shared_ptrs.

*/

int main() {
    // Create a shared_ptr to integer with value 5
    shared_ptr<int> ptr = make_shared<int>(5);
    cout << "[ptr] Address: " << ptr.get() << ", Value: " << *ptr << ", use_count: " << ptr.use_count() << endl;

    // Copy ptr to ptr1 (shared ownership)
    shared_ptr<int> ptr1(ptr);
    cout << "[ptr1] Copied from ptr -> Address: " << ptr1.get() << ", Value: " << *ptr1 
         << ", use_count (ptr & ptr1): " << ptr.use_count() << endl;

    // Reset ptr (ptr releases ownership, ptr1 still holds it)
    ptr.reset();
    cout << "[ptr] After reset -> Address: " << ptr.get() << ", use_count: " << ptr.use_count() << endl;
    cout << "[ptr1] Still valid -> Address: " << ptr1.get() << ", Value: " << *ptr1 << ", use_count: " << ptr1.use_count() << endl;

    // Check if ptr1 is the only owner
    cout << "Is ptr1 unique? : " << std::boolalpha << ptr1.unique() << endl;

    // New shared_ptr ptr2
    shared_ptr<int> ptr2 = make_shared<int>(10);
    cout << "[ptr2] Address: " << ptr2.get() << ", Value: " << *ptr2 << ", use_count: " << ptr2.use_count() << endl;

    // ptr3 shares ownership with ptr2
    shared_ptr<int> ptr3 = ptr2;
    cout << "[ptr3] Copied from ptr2 -> Address: " << ptr3.get() << ", Value: " << *ptr3 
         << ", use_count (ptr2 & ptr3): " << ptr3.use_count() << endl;

    // Swap ptr3 and ptr1 (note: they point to different memory before this)
    swap(ptr3, ptr1);
    cout << "[After Swap] ptr3 now -> Address: " << ptr3.get() << ", Value: " << *ptr3 
         << ", use_count: " << ptr3.use_count() << endl;

    return 0;
}
