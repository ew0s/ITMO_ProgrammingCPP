#pragma once

#include <iostream>
#include <vector>

template <typename T>
void findMaximal (std::vector <T> &arr, size_t size) {

    T maximal = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > maximal)
            maximal = arr[i];
    }
    std::cout << maximal << "\n";
}

template <typename T>
void push(std::vector <T> &arr, T value) {
    arr.push_back(value);
}