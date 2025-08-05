#include <iostream>
#include <memory>
using namespace std;

// ------------------------------------------------------------------------------------
// PROBLEM: Circular Reference using shared_ptr causes memory leak.
// Imagine A and B both holding shared_ptr to each other.
// Even after going out of scope, they keep each other alive -> destructors never called
// ------------------------------------------------------------------------------------

namespace problem {
    struct B; // Forward declaration

    struct A {
        shared_ptr<B> ptrB;  // A owns B
        ~A() { cout << "A destroyed" << endl; }
    };

    struct B {
        shared_ptr<A> ptrA;  // B owns A
        ~B() { cout << "B destroyed" << endl; }
    };
}

// ------------------------------------------------------------------------------------
// SOLUTION: Break the cycle using weak_ptr.
// weak_ptr does not increase reference count.
// So, when the last shared_ptr goes out of scope, both A and B can be destroyed.
// ------------------------------------------------------------------------------------

namespace solution {
    struct B; // Forward declaration

    struct A {
        shared_ptr<B> ptrB;  // A still owns B (strong)
        ~A() { cout << "A destroyed" << endl; }
    };

    struct B {
        weak_ptr<A> ptrA;    // B holds a weak reference to A (non-owning)
        ~B() { cout << "B destroyed" << endl; }
    };
}


int main() {
    {
        cout << "problem Name space" << endl;

        // Create shared instances of A and B
        shared_ptr<problem::A> a = make_shared<problem::A>();
        shared_ptr<problem::B> b = make_shared<problem::B>();

        // Both A and B hold strong references to each other
        a->ptrB = b;
        b->ptrA = a;

        // When this block ends, 'a' and 'b' go out of scope...
        // BUT their internal shared_ptrs keep them alive -> No destruction
    }
    cout << "no object was deleted" << endl << endl;

    {
        cout << "Solution Name space" << endl;

        // Same structure, but using weak_ptr to avoid circular dependency
        shared_ptr<solution::A> a = make_shared<solution::A>();
        shared_ptr<solution::B> b = make_shared<solution::B>();

        // A owns B (strong), B has weak reference to A
        a->ptrB = b;
        b->ptrA = a;

        // When this block ends, ref count drops to 0 -> both get destroyed
    }

    cout << "object were deleted" << endl;
    return 0;
}
