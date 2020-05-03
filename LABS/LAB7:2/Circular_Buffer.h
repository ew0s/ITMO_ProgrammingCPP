#pragma once

#include <memory>
#include <initializer_list>
#include "Iterator.h"


template <typename Value_Type>
class Circular_Buffer
{
public:

    friend class Iterator <Value_Type>;

    typedef Iterator <Value_Type> iterator;

    Circular_Buffer();
    Circular_Buffer (std::initializer_list<Value_Type>);
    explicit Circular_Buffer(size_t);

    iterator begin();
    iterator end();


private:

    size_t _capacity;
    size_t _size;
    std::unique_ptr <Value_Type[]> _data;
};


#include "Circular_Buffer.inl"