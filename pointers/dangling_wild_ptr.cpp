#include <stdio.h>
#include <stdlib.h>

/*
--------------------------------------------------------------
SUMMARY TABLE (Dangling vs Wild Pointer)
--------------------------------------------------------------
| Type             | Definition / Cause                               | Fix                     |
|------------------|--------------------------------------------------|--------------------------|
| Dangling Pointer | Points to memory that has been freed or deleted  | Set to NULL after free() |
| Wild Pointer     | Uninitialized pointer (points anywhere randomly) | Initialize to NULL       |
--------------------------------------------------------------
*/

int main() {

    // ----------------------------------------------------------
    // 1️⃣ Dangling Pointer Example
    // ----------------------------------------------------------
    {
        printf("\n--- [1] Dangling Pointer Example ---\n");

        int *ptr = (int *)malloc(sizeof(int));
        *ptr = 10;

        printf("Before free(): ptr = %p, *ptr = %d\n", (void*)ptr, *ptr);

        free(ptr);  // Memory is freed
        // printf("After free(): *ptr = %d\n", *ptr); ❌ undefined behavior

        // Fix: set to NULL after freeing
        ptr = NULL;
        printf("After setting NULL: ptr = %p\n", (void*)ptr);

        /*
        Interview Tip:
        - A dangling pointer still "exists" but points to invalid memory.
        - Common causes:
          1. Freeing memory without nullifying pointer
          2. Returning address of local variable from a function
          3. Using pointers to out-of-scope variables
        */
    }

    // ----------------------------------------------------------
    // 2️⃣ Wild Pointer Example
    // ----------------------------------------------------------
    {
        printf("\n--- [2] Wild Pointer Example ---\n");

        int *ptr2;  // declared but uninitialized → wild pointer
        // printf("*ptr2 = %d\n", *ptr2); ❌ undefined behavior — random address

        printf("Uninitialized pointer ptr2 = %p (garbage address)\n", (void*)ptr2);

        // Fix: always initialize pointers
        ptr2 = NULL;
        printf("After initialization: ptr2 = %p (safe)\n", (void*)ptr2);

        /*
        Interview Tip:
        - Wild pointer = "garbage" pointer — uninitialized.
        - Accessing or dereferencing it may crash your program.
        - Always initialize pointers with NULL or valid memory.
        */
    }

    return 0;
}
