#include<iostream>
using namespace std;

/*
QuickSort Algorithm
-------------------
🔹 Works on the Divide & Conquer principle.
🔹 Picks a "pivot" element and partitions the array into:
    - Left subarray: elements <= pivot
    - Right subarray: elements > pivot
🔹 Recursively sorts left and right subarrays.

👉 Common interview discussion points:
    - How to choose pivot? (last element, random pivot, median-of-three, etc.)
    - What are the time complexities in different cases?
    - Is QuickSort stable? (No, unless specially modified)
    - In-place or extra space? (QuickSort is in-place, O(log n) stack space for recursion)
    - Why QuickSort is generally faster than MergeSort in practice? (cache-friendly, in-place)
*/

/*
    Time Complexity of QuickSort:

    Case        | Time Complexity   | Reason
    ------------|------------------|-------------------------
    Best Case   | O(n log n)       | Partition always splits array in half
    Average     | O(n log n)       | Random/uniform distribution of pivots
    Worst Case  | O(n^2)           | Array already sorted & pivot chosen poorly
                                 (like always picking first/last element)

    Space Complexity:
    - O(log n) (due to recursion stack, best/avg case)
    - O(n) in worst case (skewed recursion)
*/

// Function prototypes
void swap(int *x, int *y);
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);
void print(int arr[], int size);

int main() {
    int arr[] = {3,4,5,1,2,4,7,8,9,0,1,5,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    print(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    print(arr, size);

    return 0;
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int arr[], int start, int end) {
    if (start >= end) return;

    int pivot = partition(arr, start, end);

    // Recursive calls for left and right subarrays
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int partition(int arr[], int start, int end) {
    int i = start, j = start;
    int pivot = arr[end]; // Choosing last element as pivot (common approach)

    while (i < end) {
        if (arr[i] > pivot) i++;   // element greater than pivot -> stay
        else {
            swap(&arr[i], &arr[j]); // element smaller/equal -> move to left side
            i++; j++;
        }
    }
    swap(&arr[j], &arr[end]); // place pivot in its correct sorted position

    return j; // pivot index
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
