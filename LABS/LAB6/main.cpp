#include <iostream>
#include <vector>

bool isEqual(int value) {
    return (value > 0 && value < 3);
}

bool isSorted (int x, int y) {
    return x <= y;
}

int main() {
    std::vector<int> arr = {5, 6, 7, 8};
    std::cout <<  none_of(arr.begin(), arr.end(), isEqual);
}
