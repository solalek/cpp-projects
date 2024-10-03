#include <iostream>

int * merge(int arr1[], int arr1Size, int arr2[], int arr2Size) {
    int *pArr1 = arr1;
    int *pArr2 = arr2;
    int mergedArrSize = arr1Size + arr2Size;
    int *mergedArr = new int[mergedArrSize];
    int i1 = 0;
    int i2 = 0;
    while (i1 < arr1Size and i2 < arr2Size) {
        if (*(pArr1+i1) <= *(pArr2+i2)) {
            mergedArr[i1+i2] = *(pArr1+i1);
            i1++;
        } else {
            mergedArr[i1+i2] = *(pArr2+i2);
            i2++;
        }
    }
    while (i1 < arr1Size) {
        mergedArr[i1+i2] = *(pArr1+i1);
        i1++;
    }
    while (i2 < arr2Size) {
        mergedArr[i1+i2] = *(pArr2+i2);
        i2++;
    }
    return mergedArr;
}

int * mergeSort(int arr[], int size) {
    if (size <= 1) {
        // Base case: a single element is already sorted
        int *base = new int[size];
        if (size == 1) {
            base[0] = arr[0];
        }
        return base;
    }

    // Split the array into two halves
    int mid = size / 2;
    int *firstHalf = mergeSort(arr, mid);
    int *secondHalf = mergeSort(arr + mid, size - mid);

    // Merge the two sorted halves
    int *sortedArr = merge(firstHalf, mid, secondHalf, size - mid);

    // Free the memory used by the halves
    delete[] firstHalf;
    delete[] secondHalf;

    return sortedArr;
}

int main() {
    int arr[] = { 5, 3, 4, 2, 1 };
    int *sortedArr = mergeSort(arr, 5);
    for ( int i = 0; i < 5; i++) {
        std::cout << sortedArr[i] << std::endl;
    }
}
