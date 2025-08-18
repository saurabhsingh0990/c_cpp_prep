#include <iostream>
#include<vector>

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector <int>Left;
    std:: vector <int> Right;

    for (int i = 0; i < n1; i++) {
        Left.push_back(arr[left + i]);
    }
    for (int i = 0; i < n2; i++) {
        Right.push_back(arr[mid + 1 + i]);
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {    // corrected condition
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = Left[i];
        k += 1;
        i += 1;
    }
    while(j < n2){
        arr[k] = Right[j];
        k +=1;
        j += 1;
    }
}

void mergeSort(int arr[], int left, int right){
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr , mid + 1, right);
    merge(arr, left, mid, right);
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout<< arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int arr[] = {5,4,3,2,1,6,7,8,9,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << "unsrorted arr : ";
    print(arr, size);
    mergeSort(arr, 0, size - 1);
    std::cout << "sorted arr : ";
    print(arr, size);
    
    return 0;
}