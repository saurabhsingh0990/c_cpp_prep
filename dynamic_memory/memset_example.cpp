#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Program to demonstrate how memset() works.
 * 
 * Key points for interview:
 * - memset() fills memory **byte-by-byte**, not element-wise.
 * - memset(ptr, value, num_bytes)
 * - Common use: set memory to 0 or -1 (e.g., memset(arr, 0, sizeof(arr)))
 */

void memset_int(int size) {
    int *arr = (int *)calloc(size, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\n--- Integer Array Example ---\n");
    printf("Before memset:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // memset fills bytes, not integers!
    memset(arr, 5, size * sizeof(int));

    printf("\nAfter memset (each byte set to 0x05):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // likely big weird numbers
    }
    printf("\n(Note: Values are NOT 5 because memset works byte-wise, not int-wise)\n");

    free(arr);
}

void memset_string(int size) {
    char *str = (char *)calloc(size, sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\n--- String Example ---\n");
    printf("Before memset (ASCII codes): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", str[i]); // all 0 initially
    }

    // Fill with character 'A'
    memset(str, 'A', size - 1);
    str[size - 1] = '\0'; // null terminate manually

    printf("\nAfter memset: %s\n", str);

    free(str);
}

int main() {
    int size = 10;

    memset_string(size);
    memset_int(size);

    return 0;
}
