// Algorithm: Quick Sort
// Pattern: Divide and Conquer
// Average TC: O(n log n)
// Worst TC: O(n^2) // When Pivot becomes smallest and largest repeatedly eg = {1, 2, 3, 4, 5, 6} or in descending order
// SC: O(log n)


#include <iostream>
using namespace std;


int partition (int arr[], int startIndex, int endIndex) {
    int i =  startIndex -1;
    int pivot = arr[endIndex];

    for(int j = startIndex; j < endIndex; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot in correct sorted position
    i++;
    swap(arr[i], arr[endIndex]);
    return i; // Pivot Index
    
}

void quickSort(int arr[], int startIndex, int endIndex) {
    // Base Case
    if (startIndex >= endIndex) {
        return;
    }

    int pivotIndex = partition(arr, startIndex, endIndex);

    quickSort(arr, startIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, endIndex);
}

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<endl;
    }
}
int main() {
    int arr[6] = {100, 2, 311, 89, 1, 7};
    int n = 6;
    quickSort(arr, 0, n-1);
    printArr(arr, n);
}