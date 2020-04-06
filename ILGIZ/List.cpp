#include "List.h"


List::List() :
    list_({0, nullptr, nullptr}){
}


void List::push(int numb) {

    auto pointer = new elem;
    auto prev = new elem;
    pointer = &list_;
    prev = list_.prev_;
    while (pointer->next_ != nullptr) {
        prev = pointer;
        pointer = pointer->next_;
        pointer->prev_ = prev;
    }

    pointer->numb_ = numb;
    pointer->next_ = nullptr;
}


int List::last() {

    auto pointer = new elem;
    pointer = &list_;
    while (pointer->next_ != nullptr) {
        pointer = pointer->next_;
    }

    return pointer->numb_;
}


void List::swap() {


}