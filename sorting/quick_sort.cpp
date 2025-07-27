#include<iostream>
using namespace std;

/*
QUICK SORT ALGORITHM — Key Points for Quick Revision

Steps:
1. Choose Pivot     → Usually last element (other options possible)
2. Partition Array  → Place pivot at correct position, move smaller elements left
3. Recur Left+Right → Apply same steps to sub-arrays
4. Base Case        → Stop when sub-array has 0 or 1 element (already sorted)

Time Complexity:
- Best Case:    O(n log n)    → Balanced partitions
- Average Case: O(n log n)
- Worst Case:   O(n^2)        → When pivot creates unbalanced splits (e.g. sorted input)

Space Complexity:
- O(log n) recursive stack (in-place sort, no extra array used)
*/

// Rearranges array around pivot and returns pivot's final index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing last element as pivot
    int i = low - 1;        // Tracks index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Move smaller element to correct position
        }
    }
    swap(arr[i + 1], arr[high]);  // Move pivot to its final place
    return i + 1;
}

// Recursive QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Get pivot index after partition

        // Recursively sort elements left and right of pivot
        quickSort(arr, low, pi - 1);    // Left part
        quickSort(arr, pi + 1, high);   // Right part
    }
}

// Utility to print array
void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {5, 3, 7, 1, 2, 3, 9, 10};      // Input array
    int size = sizeof(arr) / sizeof(int);      // Number of elements

    cout << "Array before sorting: ";
    print(arr, size);

    quickSort(arr, 0, size - 1);               // Apply Quick Sort

    cout << "Array after sorting: ";
    print(arr, size);

    return 0;
}
