#pragma once

#include <initializer_list>
#include <iterator>


template <class Value_Type>
class Circular_Buffer {

    class iterator : public std::iterator<std::random_access_iterator_tag, Value_Type> {
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
                return *this;
            }
            iterator &operator--() {
                ptr_--;
                return *this;
            }
            iterator operator++(Value_Type) {
                iterator tmp(*this);
                ++ptr_;
                return tmp;
            }
            iterator operator--(Value_Type) {
                iterator tmp(*this);
                --ptr_;
                return tmp;
            }

            difference_type operator-(const iterator& itr) const { return ptr_ - itr.ptr_; }
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

public:

    Circular_Buffer() = default;
    explicit Circular_Buffer(size_t capacity):
        capacity_(capacity),
        size_(0),
        buffer_(new Value_Type [capacity]),
        back_(0),
        front_(0){
    }
    Circular_Buffer(std::initializer_list<Value_Type> list) :
        capacity_(list.size()),
        size_(0),
        buffer_(new Value_Type [list.size()]),
        back_(0),
        front_(0){
        for (auto it = list.begin(); it != list.end(); it++)
            push_back(*it);
    }
    ~Circular_Buffer()
    {
        delete buffer_;
    }

    void push_back(Value_Type value)
    {
        if (!size_)
        {
            *buffer_ = value;
            front_ = iterator(buffer_);
            back_ = iterator(buffer_);
            size_++;
        }
        else if (size_ != capacity_)
        {
            increment_back();
            *back_ = value;
        }
        else
        {
            increment_back();
            increment_front();
            *back_ = value;
        }
    }

    void pop_back()
    {
        if (!size_)
            return;

        if (back_ == front_)
            size_ = 0;
        else
            decrement_back();
    }

    void push_front(Value_Type value)
    {
        if (!size_)
        {
            *front_ = value;
            size_++;
            return;
        }

        if (size_ != capacity_)
        {
            decrement_front();
            *front_ = value;
        }

        else
        {
            decrement_front();
            decrement_back();
            *front_ = value;
        }
    }

    void pop_front()
    {
        if (!size_)
            return;

        if (front_ == back_)
            size_ = 0;
        else
            increment_front();
    }

    size_t size() const {return size_;}

    iterator begin() {return iterator(buffer_);}
    iterator end() {return iterator(buffer_ + capacity_);}

    const iterator front() {return iterator(front_);}
    const iterator back() {return iterator(back_);}

private:
    Value_Type * buffer_;
    size_t size_ = 0;
    size_t capacity_ = 0;
    iterator front_;
    iterator back_;
    friend iterator;

    void increment_back()
    {
        back_++;
        size_++;
        if(back_ == iterator(buffer_ + capacity_))
            back_ = iterator(buffer_);
    }

    void decrement_back()
    {
        back_--;
        size_--;
        if (back_ == iterator(buffer_ - 1))
            back_ = iterator(buffer_ + capacity_ - 1);
    }

    void increment_front()
    {
        front_++;
        size_--;
        if (front_ == iterator(buffer_ + capacity_))
            front_ = iterator(buffer_);
    }

    void decrement_front()
    {
        front_--;
        size_++;
        if (front_ == iterator(buffer_ - 1))
            front_ = iterator(buffer_ + capacity_ - 1);
    }
};