#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int size){
    // Start from index 1 because a single-element subarray (index 0) is already sorted
    for (int i = 1; i < size; i++){ // You had i < size - 1 earlier, which skips last element. This is fixed now.
        int key = arr[i];      // Current element to be inserted in the sorted subarray
        int j = i - 1;         // Start comparing with elements on the left side

        // Move elements greater than key to one position ahead
        while(j >= 0 && key < arr[j]){
            arr[j + 1] = arr[j]; // Shift element to the right
            j -= 1;              // Move to the previous element
        }

        // Place the key at its correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {5, 3, 7, 1, 2, 3, 9, 10};  // Sample unsorted array
    int size = sizeof(arr) / sizeof(int);  // Calculate number of elements

    cout << "arr before sorting : ";
    print(arr, size);

    insertionSort(arr, size);  // Sort the array using insertion sort

    cout << "arr after sorting : ";
    print(arr, size);

    return 0;
}
