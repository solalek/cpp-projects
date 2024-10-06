#include <iostream>

template<typename T>
T * merge(T arr1[], int size1, T arr2[], int size2) {
    int i1 = 0;
    int i2 = 0;
    T *mergedArr = new T[size1+size2];
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

template<typename T>
T * sort(T arr[], int size) {
    if (size == 1) {
        T *single = new T[1];
        single[0] = arr[0];
        return single;
    }
    int mid = size/2;
    T *leftArr = sort(arr, mid);
    T *rightArr = sort(arr+mid, size-mid);
    T *sortedArr = merge(leftArr, mid, rightArr, size-mid);
    delete[] leftArr;
    delete[] rightArr;
    return sortedArr;
}

int main() {
    int arr[] = { 5, 4, 3, 2, 1 };
    int *sortedArr = sort(arr, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << sortedArr[i] << std::endl;
    }
    delete[] sortedArr;
    return 0;
}
