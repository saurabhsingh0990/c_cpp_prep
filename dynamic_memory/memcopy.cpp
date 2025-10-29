#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 📘 Topic: memcpy() demonstration
 * 
 * memcpy(dest, src, size_t num_bytes)
 * Copies 'num_bytes' from source memory to destination memory.
 * Does NOT check for overlap (use memmove if overlap is possible).
 * Works for all data types as it copies raw bytes.
 */

// -----------------------------------------------------------
// Function 1: Copy string using memcpy
// -----------------------------------------------------------
char* memcopy_string(char *str1) {
    // strlen() gives number of characters excluding '\0'
    size_t size = strlen(str1);

    // allocate memory for copy (+1 for null terminator)
    char *str2 = (char *) malloc((size + 1) * sizeof(char));
    if (str2 == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // memcpy copies raw memory (unlike strcpy which stops at '\0')
    memcpy(str2, str1, size);

    // ensure null-termination
    str2[size] = '\0';

    return str2;
}

// -----------------------------------------------------------
// ❌ Old version issue: sizeof(num_array) gives pointer size,
// not array size when passed to a function.
//
// ✅ Fix: Pass array size explicitly.
// -----------------------------------------------------------
void memcopy_int(int *num, int *num_array, size_t array_size) {
    // Copy a single integer
    int *copied_num = (int*) malloc(sizeof(int));
    if (!copied_num) {
        printf("Memory allocation failed!\n");
        return;
    }
    memcpy(copied_num, num, sizeof(int));

    // Copy entire array
    int *copied_array = (int*) malloc(array_size * sizeof(int));
    if (!copied_array) {
        printf("Memory allocation failed!\n");
        free(copied_num);
        return;
    }
    memcpy(copied_array, num_array, array_size * sizeof(int));

    // Print verification
    printf("\nOriginal num: %d | Copied num: %d\n", *num, *copied_num);

    printf("\nOriginal vs Copied Array:\n");
    for (size_t i = 0; i < array_size; i++) {
        printf("  num_array[%zu] = %d  |  copied_array[%zu] = %d\n",
               i, num_array[i], i, copied_array[i]);
    }

    // always free dynamically allocated memory
    free(copied_num);
    free(copied_array);
}

// -----------------------------------------------------------
// main() — driver function for demonstration
// -----------------------------------------------------------
int main() {
    // Example 1: memcpy with string
    char str1[] = "Saurabh Singh";
    char *copied = memcopy_string(str1);

    if (copied) {
        printf("\nOriginal string: %s", str1);
        printf("\nCopied string:   %s\n", copied);
        free(copied);
    }

    // Example 2: memcpy with integers
    int num = 10;
    int num_array[] = {1,2,3,4,5,6,7,8,9,10};
    size_t size = sizeof(num_array) / sizeof(num_array[0]);

    memcopy_int(&num, num_array, size);

    return 0;
}
