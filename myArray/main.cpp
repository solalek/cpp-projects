#include "Array.h"

int main() {
    Array arr = { 1, 2, 3, 4 };
    arr.printAll(" ");
    arr.push_back(5);
    arr.printAll(" ");
    arr.deleteAt(1);
    arr.printAll(" ");
    return 0;
}
