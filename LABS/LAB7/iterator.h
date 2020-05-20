#ifndef LAB7_2_ITERATOR_H
#define LAB7_2_ITERATOR_H

#include <iterator>
#include "Circular_Buffer.h"

template <typename Value_Type>
class iterator : public std::iterator<std::random_access_iterator_tag, Value_Type>,
                 public Circular_Buffer <Value_Type>{
private:
    Value_Type *ptr_;

public:
    using difference_type = typename std::iterator<std::random_access_iterator_tag, Value_Type>::difference_type;
    iterator() : ptr_(nullptr) {}
    explicit iterator(Value_Type *ptr) : ptr_(ptr) {}
    iterator(const iterator &it) : ptr_(it.ptr_) {}
    ~iterator() = default;

    iterator &operator+=(Value_Type idx) {
        ptr_ += idx;
        return *this;
    }
    iterator &operator-=(Value_Type idx) {
        ptr_ -= idx;
        return *this;
    }
    iterator operator++() {
        ptr_++;
        /*if (ptr_ == Circular_Buffer<Value_Type>::buffer_ + Circular_Buffer<Value_Type>::capacity_)
            ptr_ = Circular_Buffer<Value_Type>::buffer_;*/
        return *this;
    }
    iterator &operator--() {
        ptr_--;
        /*if (ptr_ == Circular_Buffer<Value_Type>::buffer_ - 1)
            ptr_ = Circular_Buffer<Value_Type>::buffer_ + Circular_Buffer<Value_Type>::capacity_ - 1;*/
        return *this;
    }
    iterator operator++(Value_Type) {
        iterator tmp(*this);
        ++ptr_;
        /*if (ptr_ == Circular_Buffer<Value_Type>::buffer_ + Circular_Buffer<Value_Type>::capacity_)
            ptr_ = Circular_Buffer<Value_Type>::buffer_;*/
        return tmp;
    }
    iterator operator--(Value_Type) {
        iterator tmp(*this);
        --ptr_;
        /*if (ptr_ == Circular_Buffer<Value_Type>::buffer_ - 1)
            ptr_ = Circular_Buffer<Value_Type>::buffer_ + Circular_Buffer<Value_Type>::capacity_ - 1;*/
        return tmp;
    }

    difference_type operator - (const iterator& itr) const { return ptr_ - itr.ptr_; }
    iterator operator + (Value_Type idx) {return iterator(ptr_ + idx);}
    iterator operator - (Value_Type idx) {return iterator(ptr_ - idx);}

    Value_Type &operator*() const { return *ptr_; }
    Value_Type *operator->() const { return ptr_; }
    Value_Type &operator[](const Value_Type idx) { return ptr_[idx]; }

    bool operator == (const iterator & other) const {return other.ptr_ == this->ptr_;}
    bool operator != (const iterator & other) const {return other.ptr_ != this->ptr_;}
    bool operator < (const iterator & other) const {return other.ptr_ < this->ptr_;}
    bool operator > (const iterator & other) const {return other.ptr_ > this->ptr_;}
    bool operator >= (const iterator & other) const {return other.ptr_ >= this->ptr_;}
    bool operator <= (const iterator & other) const {return other.ptr_ <= this->ptr_;}
};

#endif //LAB7_2_ITERATOR_H
