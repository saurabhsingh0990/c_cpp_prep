#include <stdio.h>
#include <stdlib.h>

/*
 * Function: create_array
 * ----------------------
 * Dynamically allocates memory for an integer array of given size using malloc().
 * 
 * malloc() allocates 'size * sizeof(int)' bytes from the heap.
 * It returns a void pointer, which is then typecasted to (int *).
 * 
 * NOTE (for interview):
 * - malloc() allocates memory but DOES NOT initialize it (values are garbage until explicitly set).
 * - Always check if malloc() returned NULL (allocation failure).
 * - Memory allocated via malloc() must be freed manually using free().
 */
int* create_array(int size) {
    int *array = (int *)malloc(sizeof(int) * size);  // dynamic allocation

    // (optional but good for interview): check for allocation failure
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // exit program gracefully
    }

    // populate array with values 1, 2, 3, ... n
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;  // same as *(array + i) = i + 1
    }

    return array;  // return pointer to the dynamically allocated memory
}

/*
 * Function: print_array
 * ---------------------
 * Prints the array elements using pointer arithmetic.
 *
 * NOTE:
 * - ptr[i] is equivalent to *(ptr + i)
 * - Printing directly via pointer shows understanding of pointer manipulation.
 */
void print_array(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("\narray[%d] = %d", i + 1, *(ptr + i));
    }
}

int main() {
    // Ask user for array size
    printf("\nPlease enter the size of the array: ");
    int size;
    scanf("%d", &size);

    /*
     * Dynamically create array using malloc().
     * The memory is allocated on the HEAP (not stack).
     * The pointer 'arr_ptr' resides on the STACK and holds the address of heap memory.
     */
    int *arr_ptr = create_array(size);

    // Print array contents
    print_array(arr_ptr, size);

    /*
     * Important interview note:
     * - free() deallocates heap memory previously allocated with malloc(), calloc(), or realloc().
     * - Not calling free() results in a memory leak (allocated memory stays reserved even after program ends).
     * - Setting pointer to NULL after free() prevents dangling pointer issues.
     */
    free(arr_ptr);   // free allocated heap memory
    arr_ptr = NULL;  // avoid dangling pointer

    /*
     * Interview Tip:
     * - malloc() vs calloc(): malloc leaves memory uninitialized; calloc initializes to zero.
     * - realloc(): used to resize an existing memory block.
     * - All three functions allocate from the heap, and their returned pointer must be freed.
     */

    return 0;
}
