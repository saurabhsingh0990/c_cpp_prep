#include <stdio.h>
#include <stdlib.h>

/*
 * Program to demonstrate the difference between malloc() and calloc()
 *
 * malloc()  → allocates raw memory (contains garbage values)
 * calloc()  → allocates and initializes memory to zero
 */

int main() {
    int n = 5;

    // Allocate memory using malloc()
    int *m_arr = (int *)malloc(n * sizeof(int));

    // Allocate memory using calloc()
    int *c_arr = (int *)calloc(n, sizeof(int));

    if (m_arr == NULL || c_arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\n--- Before Initialization ---\n");
    printf("malloc() values:\n");
    for (int i = 0; i < n; i++)
        printf("m_arr[%d] = %d\n", i, m_arr[i]);  // ❗ undefined garbage values

    printf("\ncalloc() values:\n");
    for (int i = 0; i < n; i++)
        printf("c_arr[%d] = %d\n", i, c_arr[i]);  // ✅ all zeros

    printf("\n--- After Initialization ---\n");
    for (int i = 0; i < n; i++) {
        m_arr[i] = (i + 1) * 10;
        c_arr[i] = (i + 1) * 10;
    }

    printf("malloc() values after assignment:\n");
    for (int i = 0; i < n; i++)
        printf("m_arr[%d] = %d\n", i, m_arr[i]);

    printf("\ncalloc() values after assignment:\n");
    for (int i = 0; i < n; i++)
        printf("c_arr[%d] = %d\n", i, c_arr[i]);

    // Free allocated memory
    free(m_arr);
    free(c_arr);
    m_arr = c_arr = NULL;

    return 0;
}
