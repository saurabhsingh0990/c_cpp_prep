#include<iostream>
using namespace std;

// Demonstration of bubble sort using:
// 1. Static array (fixed-size, declared at compile time)
// 2. swap() implemented using pointers (pass-by-reference via pointer dereferencing)


// Custom swap function using pointers to modify original values
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble sort implementation for static array
// Time Complexity: O(n^2) in worst/average case, O(n) in best case (if optimized)
// Sorting in ascending order by repeatedly swapping adjacent elements if out of order
void bubble_sort_array(int arr[], int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) 
                swap(&arr[j], &arr[j + 1]); // swapping values via pointers
        }
    }
}

// Utility function to print array contents
void print(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    // Static array initialization
    int arr[] = {5, 2, 7, 4, 6, 3, 9};

    // Calculate number of elements in array
    int size = sizeof(arr) / sizeof(int);

    // Print array before sorting
    cout << "Unsorted array : ";
    print(arr, size);

    // Perform bubble sort
    bubble_sort_array(arr, size);

    // Print array after sorting
    cout << "Sorted array   : ";
    print(arr, size);

    return 0;
}
