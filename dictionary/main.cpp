#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <ctime>

template<typename T1, typename T2>
class Dict{
private:
    std::vector<T1> keys;
    std::vector<T2> values;

    int search(std::vector<T1> &arr, T1 value) {
        int left = 0;
        int right = arr.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == value) {
                return mid;
            }
            if ( arr[mid] > value ) {
                right = mid-1;
            } else if ( arr[mid] < value ) {
                left = mid+1;
            }    
        }
        return left;
    }

public:
    void set(T1 key = T1(), T2 value = T2()) {
        int index = search(keys, key);
        keys.insert(keys.begin()+index, key);
        values.insert(values.begin()+index, value);
    }
    T2 & operator[] (const T1 key) {
        int index = search(keys, key);
        return values[index];
    }
    void showKeys() {
        for (auto &el : keys) {
            std::cout << el << std::endl;
        }
    }
};

int main() {
    Dict<std::string, int> myDict;
    myDict.set("age", 18);
    myDict.set("weight", 70);
    myDict.set("height", 170);
    std::cout << myDict["age"] << std::endl;
    std::cout << myDict["weight"] << std::endl;
    std::cout << myDict["height"] << std::endl;
    myDict.showKeys();
    return 0;
}
