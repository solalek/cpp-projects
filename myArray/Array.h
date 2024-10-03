#ifndef ARRAY_H
#define ARRAY_H
#include <cmath>
#include <initializer_list>
#include <string>
#include <iostream>

template<typename T>
class Array {
private:
    int capacity;
    T *arr;
    int Size;
    T * merge(T arr1[], int size1, T arr2[], int size2);
    T * _merge_sort(T arr[], int size);
public:

    int getSize() { return Size; }
    Array(int capacity = 1);
    Array(std::initializer_list<T> list);
    ~Array();
    void push_back(T value);
    void pop_back();
    void push_front(T value);
    void pop_front();
    void printAll(std::string end = "\n");
    T & operator [] (const int index);
    void insert(int index, T value);
    void merge_sort();
    T * new_arr_merge_sort();
    int find(T value);
    void deleteAt(int index);

};

#include "Array.tpp"

#endif
