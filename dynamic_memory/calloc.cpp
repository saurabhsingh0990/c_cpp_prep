#include <stdio.h>
#include <stdlib.h>

/*
 * Function: create_string
 * -----------------------
 * Dynamically allocates memory for a string of given size using calloc(),
 * takes user input for each character, and returns the pointer to that string.
 *
 * Key Points for Interview:
 *  - calloc() initializes allocated memory to zero (unlike malloc()).
 *  - Always check if allocation succeeded (NULL check).
 *  - Always add '\0' at the end to make it a proper C string.
 */
char* create_string(int size) {
    // Allocate (size + 1) chars to store string + null terminator '\0'
    char *name = (char *)calloc(size + 1, sizeof(char));

    // Always check for successful memory allocation
    if (name == NULL) {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }

    printf("\nPlease enter %d characters (press Enter after each):\n", size);
    for (int i = 0; i < size; i++) {
        // Space before %c skips whitespace/newline characters
        scanf(" %c", &name[i]);
    }

    // Explicitly terminate string (important even though calloc zeroes memory)
    name[size] = '\0';
    return name;
}

/*
 * Function: print_char
 * --------------------
 * Prints each character of the string with its index
 * and then prints the entire string.
 *
 * Key Points for Interview:
 *  - ptr[i] == *(ptr + i) → pointer arithmetic equivalence.
 *  - Loop until '\0' to print full string safely.
 */
void print_char(char *ptr, int size) {
    for (int i = 0; ptr[i] != '\0'; i++) {
        printf("\narray[%d] = %c", i + 1, *(ptr + i));
    }
    printf("\nComplete string is: %s\n", ptr);
}

/*
 * Function: main
 * --------------
 * Demonstrates dynamic memory allocation for a string.
 *
 * Interview Notes:
 *  - Always free() heap memory to prevent memory leaks.
 *  - Setting pointer to NULL after freeing avoids dangling pointers.
 *  - calloc() syntax: void* calloc(num_elements, size_of_each_element)
 */
int main() {
    int size;
    printf("\nPlease enter size of string: ");
    scanf("%d", &size);

    // Call function to allocate and populate string
    char *name_ptr = create_string(size);
    if (name_ptr == NULL) return 1;  // Handle memory allocation failure

    print_char(name_ptr, size);

    // Clean up dynamically allocated memory
    free(name_ptr);       // Prevent memory leak
    name_ptr = NULL;      // Avoid dangling pointer

    return 0;
}
