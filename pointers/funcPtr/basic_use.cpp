// ==========================================================
//  FUNCTION POINTERS IN C  —  BASIC USE CASES & EXAMPLES
//  This file covers all fundamental function pointer scenarios:
//   1. Declaring and assigning function pointers
//   2. Calling functions using pointers
//   3. Passing and returning function pointers (basic idea)
//   4. Array of function pointers
// ==========================================================

#include <stdio.h>

// --- Example functions to demonstrate function pointers ---
int add(int x, int y){ 
    return (x + y); 
} 

int substract(int x, int y){ 
    return x - y; 
} 

int multiply(int x, int y){ 
    return x * y; 
} 

void swap(int *x, int *y){ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void print(){ 
    printf("\nDemo for function pointer");
} 

int main() { 
    
    // ======================================================
    // 1️⃣ BASIC FUNCTION POINTER (no parameters)
    // ------------------------------------------------------
    // Syntax: <return_type> (*<pointer_name>)(<params>) = <function_name>;
    // Used to call a function indirectly via a pointer.
    // ======================================================
    void (*print_ptr)() = print; 
    print_ptr(); // equivalent to calling print();
    
    // ======================================================
    // 2️⃣ FUNCTION POINTER WITH PARAMETERS
    // ------------------------------------------------------
    // Function pointers can store addresses of any function
    // matching the same signature (return + parameter types).
    // ======================================================
    int (*add_ptr)(int, int) = add; 
    printf("\nAddition done: %d", add_ptr(5, 6)); 
    
    // ======================================================
    // 3️⃣ FUNCTION POINTER TO VOID FUNCTION (with arguments)
    // ------------------------------------------------------
    // Useful when function modifies values via pointers.
    // ======================================================
    int x = 9, y = 7; 
    printf("\nBefore swap: %d , %d", x, y); 
    
    void (*swap_ptr)(int *, int *) = swap; 
    swap_ptr(&x, &y); // calling via pointer
    printf("\nAfter swap: %d , %d", x, y); 
    
    // ======================================================
    // 4️⃣ ARRAY OF FUNCTION POINTERS
    // ------------------------------------------------------
    // Commonly used for menu-driven programs or dispatch tables.
    // Allows selecting a function dynamically at runtime.
    // ======================================================
    printf("\n\nArray of function pointers demo:");
    
    const char* operations[] = {"add", "substract", "multiply"}; 
    int (*array_ptr[])(int, int) = {add, substract, multiply}; 
    
    int operation = 0; // choose which function to call
    printf("\n%s : %d", operations[operation], array_ptr[operation](5, 10)); 
    
    // ======================================================
    // ✅ Summary:
    //  - Function pointers help call functions dynamically.
    //  - Commonly used in callbacks, event handling, and drivers.
    //  - Arrays of function pointers are used in state machines.
    // ======================================================

    return 0; 
}
