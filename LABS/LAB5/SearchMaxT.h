#pragma once

#include <iostream>
#include <vector>


template<typename T>
class Array {
public:

    void findMaximal() {

        T maximal = array_[0];
        for (int i = 0; i < array_.size(); i++) {
            if (array_[i] > maximal)
                maximal = array_[i];
        }
        std::cout << maximal << "\n";
    }

    void push(T value) {
        array_.push_back(value);
    }

private:
    std::vector<T> array_;
};