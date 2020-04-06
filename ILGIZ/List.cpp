#include "List.h"
#include <iostream>


List::List() :
    list_({0, nullptr, nullptr}),
    length_(0),
    top_(nullptr),
    last_(nullptr){
}


void List::push(int numb) {

    auto pointer = &list_;

    if (length_ == 0) {
        list_.numb_ = numb;
        length_++;
        top_ = &list_;
        last_ = &list_;
    }

    else {

        auto newElem = new elem {numb, nullptr, nullptr};

        while (pointer->next_ != nullptr) {
            pointer = pointer->next_;
        }

        newElem->prev_ = pointer;
        pointer->next_ = newElem;
        length_++;
        last_ = pointer->next_;
    }
}


int List::last() {
    return last_->numb_;
}


void List::swap() {

    auto lPointer = top_;
    auto rPointer = last_;

    for (int i = 0; i < length_ / 2; i++) {

        std::swap (lPointer->numb_, rPointer->numb_);
        lPointer = lPointer->next_;
        rPointer = rPointer->prev_;
    }
}


int List::get(int numb) {

    unsigned int index;

    try {
        if (numb == 0) {
            throw ("Invalid index\n");
        }
    }
    catch (const char* exception) {
        std::cout << exception;
        exit(-1);
    }

    if (numb > 0) {

        index = numb % length_;

        if (index == 0)
            index = length_;
    }

    else {
        index = length_ - (std::abs(numb) % length_) + 1;

        if (std::abs(numb) % length_ == 0)
            index = 1;
    }

    auto pointer = &list_;
    while(index != 1) {
        pointer = pointer->next_;
        index--;
    }

    return pointer->numb_;

}