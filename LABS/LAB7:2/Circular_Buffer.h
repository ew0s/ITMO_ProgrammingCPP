#pragma once

#include <iostream>
#include <cstdio>


template <typename T>
class Circular_buffer {

public:

    Circular_buffer();
    Circular_buffer(std::initializer_list <T>);
    ~Circular_buffer();

    void push_back(T);
    void pop_back();

    void push_front(T);
    void pop_front();

private:

    T* data_;
    T* begin_;
    T* end_;
    size_t size_;

};
