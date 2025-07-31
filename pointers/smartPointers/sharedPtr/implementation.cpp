
#include <iostream>
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

template<typename T>
class SharedPtr{
    private:
        T *data;
        int *ref_count;
    public:
        SharedPtr(): data(nullptr), ref_count(new int (0)) {};
        SharedPtr (T *val = nullptr): data(val), ref_count(new int (1)) {};

        SharedPtr(const SharedPtr& obj){
                data = obj.data;
                ref_count = obj.ref_count;
                ++(*ref_count);            
        }

        T operator*(){
            return *data;
        }

        T* get(){
            return data;
        }
        int use_count(){
            return *ref_count;
        }


};

int main(){
    SharedPtr <int> ptr(new int (5));
    cout << "[ptr] value: " << *ptr  << " address : "<< ptr.get() << ", use_count: " << ptr.use_count() << endl;
    SharedPtr<int> ptr1 = ptr;
    cout << "[ptr1] value: " << *ptr1  << " address : "<< ptr1.get() << ", use_count: " << ptr1.use_count() << endl;
    return 0;
}