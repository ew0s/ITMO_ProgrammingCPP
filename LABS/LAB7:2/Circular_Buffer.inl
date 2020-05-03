#pragma once

#include "Circular_Buffer.h"


template <typename Value_Type>
Circular_Buffer<Value_Type>::Circular_Buffer() :
    _size(0),
    _capacity(0),
    _data(nullptr){
}


template <typename Value_Type>
Circular_Buffer<Value_Type>::Circular_Buffer(size_t capacity) :
    _size(0),
    _capacity(capacity),
    _data (new Value_Type[capacity]){
}


template <typename Value_Type>
Circular_Buffer<Value_Type>::Circular_Buffer(std::initializer_list<Value_Type> init_list) :
    _size(0),
    _capacity(init_list.size()),
    _data (new Value_Type[init_list.size()])
{
    std::copy(init_list.begin(), init_list.end(), _data.get());
}


/*template <typename Value_Type>
Iterator <Value_Type> Circular_Buffer <Value_Type>:: begin ()
{
    return (_data.get());
}*/


template <typename Value_Type>
Iterator <Value_Type> Circular_Buffer <Value_Type>:: begin ()
{
    return (_data.get());
}


template <typename Value_Type>
Iterator <Value_Type> Circular_Buffer <Value_Type>:: end ()
{
    return (_data.get() + _size);
}