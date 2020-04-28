#pragma once


#include <cstdio>
#include <queue>
#include <stdexcept>
#include <algorithm>


template <typename T>
class CCircular_Buffer : public std::queue<T>{

public:

    CCircular_Buffer();
    explicit CCircular_Buffer(unsigned int capacity);
    ~CCircular_Buffer();

    void push_back(T);
    void pop_back();

    void push_front(T);
    void pop_front();

    void push(int, T); // push by random access
    void pop(int, T); // pop by random access

    T back() const;
    T front() const;

    inline T& operator [] (int) const;

    inline int size() const;

private:

    size_t size_;
    size_t capacity_;
    T* buffer_;
    unsigned int head_;
    unsigned int tail_;

    inline void increment_head();
    inline void increment_tail();
    inline void decrement_tail();
};

#include "Circular_buffer.inl"