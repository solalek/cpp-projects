#include <iostream>

int * merge(int arr1[], int size1, int arr2[], int size2) {
    int i1 = 0;
    int i2 = 0;
    int *mergedArr = new int[size1+size2];
    while (i1 < size1 and i2 < size2) {
        if (arr1[i1] < arr2[i2]) {
            mergedArr[i1+i2] = arr1[i1];
            i1++;
        } else {
            mergedArr[i1+i2] = arr2[i2];
            i2++;
        }
    }
    while (i1 < size1) {
        mergedArr[i1+i2] = arr1[i1];
        i1++;
    }
    while (i2 < size2) {
        mergedArr[i1+i2] = arr2[i2];
        i2++;
    }
    return mergedArr;
}

int * mergeSort(int arr[], int size) {
    if (size == 1) {
        return arr;
    }
    int mid = size/2;
    return merge(mergeSort(arr, mid), mid, mergeSort(arr+mid, size-mid), size-mid);
}

int main() {
    int arr1[] = {2, 4, 6};
    int arr2[] = {1, 3, 5};
    int arr3[] = { 5, 3, 4, 2, 1 };
    int *merged = merge(arr1, 3, arr2, 3);
    int *sortedArr = mergeSort(arr3, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << sortedArr[i] << std::endl;
    }
    return 0;
}
