#include <stdio.h>
#include <stdlib.h>

/*
 * Program to demonstrate a memory leak scenario.
 *
 * Key Points for Interview:
 *  - A memory leak occurs when dynamically allocated memory is not freed.
 *  - Over time, memory leaks can lead to increased memory usage and exhaustion.
 *  - Always pair malloc/calloc with free to release memory back to the system.
 */
int main() {
    printf("\n--- Memory Leak Demonstration ---\n");    
    for (int i = 0; i < 5; i++) {
        // Dynamically allocate memory for an integer
        int *leaked_memory = (int *)malloc(sizeof(int));
        *leaked_memory = i * 10;

        printf("Iteration %d: Allocated memory at %p with value %d\n", 
               i + 1, (void*)leaked_memory, *leaked_memory);

        // Intentionally NOT freeing the allocated memory
        // free(leaked_memory); // ❌ Memory leak occurs here
    }
    printf("\nNote: Memory allocated in each iteration was not freed, leading to a memory leak.\n");
    return 0;
}