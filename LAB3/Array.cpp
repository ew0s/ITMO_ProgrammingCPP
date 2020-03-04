#include "Array.h"
#include <vector>
#include <iostream>

Array::Array (std::vector <int> arr) {
    m_arr = std::move(arr);
}

Array operator + (Array &arr1, Array &arr2) {

    std::vector <int> newArr;

    for (int i : arr1.m_arr)
        newArr.push_back(i);

    for (int i : arr2.m_arr)
        newArr.push_back(i);

    return Array(newArr);
}

bool operator == (Array &arr1, Array &arr2) {
    return arr1.m_arr.size() == arr2.m_arr.size();
}

bool operator != (Array &arr1, Array &arr2) {
    return !(arr1 == arr2);
}

bool operator > (Array &arr1, Array &arr2) {
    return arr1.m_arr.size() > arr2.m_arr.size();
}

bool operator < (Array &arr1, Array &arr2) {
    return arr1.m_arr.size() < arr2.m_arr.size();
}

void Array::print () {
    for (int i : m_arr){
        std::cout << i << " ";
    }
    std::cout << "\n";
}