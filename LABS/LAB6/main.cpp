#include <iostream>
#include <vector>
#include "Algorithms.h"

bool isEqual(int value) {
    return (value > 0 && value < 3);
}

bool isSorted (int x, int y) {
    return x <= y;
}

int main() {
    std::vector<int> arr = {5, 6, 7, 8};
    std::cout << ((none_of(arr.begin(), arr.end(), isEqual)) ? "YES" : "NO") << std::endl;
    std::cout << ((is_sorted(arr.begin(), arr.end(), isSorted)) ? "YES" : "NO") << std::endl;
    std::cout << ((find_backward(arr.begin(), arr.end(), 7))) << std::endl;
}
