// Algorithm: Merge Sort
// Pattern: Divide and Conquer
// TC: O(n log n)
// SC: O(n)


#include <iostream>
#include <vector>
using namespace std;

void merge (int arr[], int startIndex, int mid, int endIndex) {
    vector<int> temp;
    int i = startIndex;
    int j = mid + 1;

    while(i <= mid && j <= endIndex) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid){
        temp.push_back(arr[i++]);
    }
    while (j <= endIndex) {
        temp.push_back(arr[j++]);
    }

    // For Copying to original Arrray
    for(int index = startIndex, x = 0; index <= endIndex; index++){
        arr[index] = temp[x++];
    }

}


// Dividing

void mergeSort(int arr[], int startIndex, int endIndex) {

    // Base Case 
    if(startIndex >= endIndex) {
        return;
    }
    // Defining Mid
    int mid = startIndex + (endIndex - startIndex) / 2;
    mergeSort(arr, startIndex, mid); // For Left Side
    mergeSort(arr, mid + 1, endIndex); // For Right Side
    // Conquering
    merge(arr, startIndex, mid, endIndex ); // For Merging Both left and right Sides
}

// Printing Function

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i]<<endl;
    }
}

int main() {
    int arr[6] = {6, 5, 8, 1, 0, 9};  // We can give Any Input!
    int n = 6;
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}
