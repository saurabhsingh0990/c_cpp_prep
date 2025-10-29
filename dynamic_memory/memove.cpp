#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 🔹 Difference between memcpy() and memmove():
 *
 * memcpy(dest, src, n)
 *   - Copies n bytes from src to dest.
 *   - UNDEFINED behavior if memory regions overlap.
 *
 * memmove(dest, src, n)
 *   - Also copies n bytes from src to dest.
 *   - SAFE for overlapping memory regions.
 *   - Internally uses a temporary buffer.
 *
 * ✅ In short:
 *      - Use memcpy() when you are sure memory does not overlap.
 *      - Use memmove() when overlapping can occur.
 */

// Function to demonstrate overlapping issue
void demonstrate_overlap() {
    char str[50] = "HelloWorld";

    printf("\nOriginal string: %s", str);

    // Overlapping copy using memcpy (❌ unsafe)
    // Here, destination starts within the source region.
    memcpy(str + 5, str, 5);  
    printf("\nAfter memcpy overlap (undefined behavior): %s", str);

    // Reset string
    strcpy(str, "HelloWorld");

    // Overlapping copy using memmove (✅ safe)
    memmove(str + 5, str, 5);
    printf("\nAfter memmove overlap (safe behavior):      %s\n", str);
}

// Function to show normal non-overlapping copy
void demonstrate_safe_copy() {
    char src[] = "Saurabh";
    char dest[20];

    // Non-overlapping, memcpy is fine here
    memcpy(dest, src, strlen(src) + 1);
    printf("\nUsing memcpy (non-overlapping):\n Source: %s | Dest: %s", src, dest);

    // Now with memmove (both behave the same for non-overlapping)
    char dest2[20];
    memmove(dest2, src, strlen(src) + 1);
    printf("\nUsing memmove (non-overlapping):\n Source: %s | Dest: %s\n", src, dest2);
}

int main() {
    printf("🔸 Demonstrating memcpy() vs memmove() 🔸\n");
    
    demonstrate_safe_copy();   // Case 1: Non-overlapping copy
    demonstrate_overlap();     // Case 2: Overlapping memory regions

    return 0;
}
