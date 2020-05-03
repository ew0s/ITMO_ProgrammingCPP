#pragma once

#include "Circular_Buffer.h"


template <typename Value_Type>
class Iterator {

public:

    Iterator (const Iterator &ptr):
        _ptr(ptr){
    };

    bool operator != (Iterator const & other) const {return other._ptr != this->_ptr;};
    bool operator == (Iterator const & other) const {return other._ptr == this->_ptr;};
    Iterator& operator ++ () { return Iterator(this->_ptr++);};

private:

    Value_Type * _ptr;
};
