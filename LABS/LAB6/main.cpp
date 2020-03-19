#include <iostream>
#include <vector>
#include "Algorithms.h"

template <typename T>
bool isEqual(T value) {
    return (value > 0 && value < 3);
}

template <typename T>
bool isSorted (T x, T y) {
    return x <= y;
}

int main() {
    std::vector<int> arr = {5, 6, 7, 8};
    std::cout <<  none_of(arr.begin(), arr.end(), isEqual);
}
