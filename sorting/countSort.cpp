#include<iostream>

void countSort(int arr[], int size){
    int count[10] = {0};
    for(int i = 0 ; i < size; i++){
        count[arr[i]] += 1;
    }
    int placeHolder = 0;
    for(int i = 0; i < 10; i++){
        while (count[i]--)
        {
            arr[placeHolder++] = i;
        }
         
    }
}

void print(int arr[], int size){
    for(int i = 0 ; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main(){
    int arr[] = {2,4,5,3,4,8,6,5,5,4,3,2};
    int size = sizeof(arr)/ sizeof(arr[0]);
    std::cout << "unsorted array : ";
    print(arr ,size);
    std::cout << "sorted array : ";
    countSort(arr, size);
    print(arr , size);
}