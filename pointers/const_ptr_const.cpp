#include <stdio.h>

/*
--------------------------------------------------------------
SUMMARY TABLE (for quick revision)
--------------------------------------------------------------
| Combination Type             | Pointer | Value  | Meaning                     |
|-------------------------------|----------|--------|-----------------------------|
| non-const ptr to non-const    | mutable  | mutable| can change both ptr & value |
| non-const ptr to const        | mutable  | const  | can move ptr, not *ptr      |
| const ptr to non-const        | const    | mutable| fixed ptr, can change *ptr  |
| const ptr to const            | const    | const  | neither ptr nor *ptr change |
--------------------------------------------------------------
SYNTAX REFERENCE:
int *ptr;                      // non-const ptr to non-const
const int *ptr; or int const *ptr;   // non-const ptr to const
int *const ptr = &a;           // const ptr to non-const
const int *const ptr = &a;     // const ptr to const
--------------------------------------------------------------
*/

int main() {

    // ----------------------------------------------------------
    // 1️⃣ Non-const pointer to non-const value
    // ----------------------------------------------------------
    {
        printf("\n--- [1] Non-const ptr to Non-const value ---\n");
        int a = 10;
        int *ptr = &a;

        printf("Initial: *ptr = %d\n", *ptr);
        *ptr = 20;            // ✅ allowed — can modify value
        printf("After *ptr=20: a = %d\n", a);

        int b = 30;
        ptr = &b;             // ✅ allowed — can point to another variable
        printf("After ptr=&b: *ptr = %d\n", *ptr);
    }

    // ----------------------------------------------------------
    // 2️⃣ Non-const pointer to const value
    // ----------------------------------------------------------
    {
        printf("\n--- [2] Non-const ptr to Const value ---\n");

        const int A = 50;
        const int *ptr = &A;   // or int const *ptr = &A;

        printf("A = %d, *ptr = %d\n", A, *ptr);
        // *ptr = 60; ❌ not allowed — cannot modify value through ptr

        int B = 70;
        ptr = &B;              // ✅ allowed — can change where ptr points
        printf("ptr now points to B = %d\n", *ptr);

        B = 80;                // ✅ allowed — value changed directly
        printf("After B=80, *ptr = %d (value updated)\n", *ptr);

        /*
        Interview Tip:
        - const applies to what’s *left* of it.
        - `const int *ptr` => const applies to int (value is const)
        - pointer itself is not const.
        */
    }

    // ----------------------------------------------------------
    // 3️⃣ Const pointer to non-const value
    // ----------------------------------------------------------
    {
        printf("\n--- [3] Const ptr to Non-const value ---\n");

        int A = 90;
        int *const ptr = &A;   // const pointer, non-const data

        printf("Initial: *ptr = %d\n", *ptr);
        *ptr = 95;             // ✅ allowed — can modify value
        printf("After *ptr=95: A = %d\n", A);

        int C = 80;
        // ptr = &C; ❌ not allowed — ptr cannot point elsewhere
        printf("Ptr still points to A, value = %d\n", *ptr);

        /*
        Interview Tip:
        - `int *const ptr` => const applies to the pointer itself.
        - You can modify the data but not the address.
        */
    }

    // ----------------------------------------------------------
    // 4️⃣ Const pointer to const value
    // ----------------------------------------------------------
    {
        printf("\n--- [4] Const ptr to Const value ---\n");

        int A = 100;
        const int *const ptr = &A;

        printf("Initial: *ptr = %d\n", *ptr);
        // *ptr = 110; ❌ not allowed — cannot modify value
        // ptr = &otherVar; ❌ not allowed — cannot repoint

        A = 120;               // ✅ allowed — direct modification
        printf("After A=120, *ptr = %d\n", *ptr);

        /*
        Interview Tip:
        - Complete immutability through pointer.
        - Often used for read-only access.
        */
    }

    return 0;
}
