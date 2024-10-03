
template<typename T>
T * Array<T>::merge(T arr1[], int size1, T arr2[], int size2) {
    T *mergedArr = new T[size1 + size2];
    int i1 = 0;
    int i2 = 0;
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
T * Array<T>::_merge_sort(T arr[], int size) {
    if (size == 1) {
        return arr;
    }
    int mid = size/2;
    return merge(
            _merge_sort(arr, mid), mid, 
            _merge_sort(arr+mid, size-mid), size-mid);
}

template<typename T>
Array<T>::Array(int capacity) {
        this->capacity = capacity;
        this->arr = new T[capacity];
        this->Size = 0;
        for (int i = 0; i < capacity; i++) {
            arr[i] = 0;
        }
}

template<typename T>
Array<T>::Array(std::initializer_list<T> list) {
    this->capacity = list.size();
    this->arr = new T[capacity];
    int index = 0;
    for (const auto &el : list) {
        arr[index++] = el;
    }
    this->Size = list.size();
}

template<typename T>
Array<T>::~Array() {
    delete[] arr;
    arr = nullptr;
}

template<typename T>
void Array<T>::push_back(T value) {
    if (Size == capacity) {
        capacity *= 2;
        T *cache = new T[capacity];
        for (int i = 0; i < Size; i++) {
            cache[i] = arr[i];
        } 
        delete[] arr;
        arr = cache;
        cache = nullptr;
    }
    arr[Size] = value;
    Size++;
}

template<typename T>
void Array<T>::pop_back() {
    Size--;
    arr[Size] = 0;
}

template<typename T>
void Array<T>::push_front(T value) {
    if (Size == capacity) {
        capacity *= 2;
    } 
    T *cache = new T[capacity];
    cache[0] = value;
    for (int i = 0; i < Size; i++) {
        cache[i+1] = arr[i];
    }
    delete[] arr;
    arr = cache;
    cache = nullptr;
    Size++;
}

template<typename T>
void Array<T>::pop_front() {
    T *cache = new T[capacity];
    for (int i = 1; i < Size; i++) {
        cache[i-1] = arr[i];
    }
    delete[] arr;
    arr = cache;
    cache = nullptr;
    Size--;
}

template<typename T>
void Array<T>::printAll(std::string end) {
    for (int i = 0; i < Size; i++) {
        std::cout << arr[i] << end;
    }
    if (end != "\n") {
        std::cout << std::endl;
    }
}

template<typename T>
T & Array<T>::operator [] (const int index) {
    try {
        if (index > capacity-1 or index < 0) {
            throw -1;
        }
        return arr[index];
    } catch (const int ex) {
        std::cout << "Not valid index" << std::endl;
        exit(ex);
    }
}

template<typename T>
void Array<T>::insert(int index, T value) {
    if (Size == capacity) {
        capacity *= 2;
        T *cache = new T[capacity];
        for (int i = 0; i < Size; i++) {
            cache[i] = arr[i];
        }
        delete[] arr;
        arr = cache;
        cache = nullptr;
    }
    if (index == Size) {
        push_back(value);
    } else if (index == 0) {
        push_front(value);
    } else {
        for (int i = Size; i > index; i--) {
            arr[i] = arr[i-1];
        }
        arr[index] = value;
    }
}

template<typename T>
void Array<T>::merge_sort() {
    T *sortedArr = _merge_sort(arr, Size);
    delete[] arr;
    arr = sortedArr;
    sortedArr = nullptr;
}

template<typename T>
T * Array<T>::new_arr_merge_sort() {
    return _merge_sort(arr, Size);
}

template<typename T>
int Array<T>::find(T value) {
    int left = 0;
    int right = Size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

template<typename T>
void Array<T>::deleteAt(int index) {
    if (index == 0) {
        pop_front();
    } else if (index == Size - 1) {
        pop_back();
    } else {
        for (int i = index; i < Size; i++) {
            arr[i] = arr[i+1];
        }
    }
    Size--;
}
