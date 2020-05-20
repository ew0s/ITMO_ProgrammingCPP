#pragma once

#include <initializer_list>


template <class Value_Type>
class Circular_Buffer {

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

    [[nodiscard]] size_t size() const {return size_;}

    iterator <Value_Type> begin() const {return iterator(buffer_);}
    iterator <Value_Type> end() const {return iterator(buffer_ + capacity_);}

    Value_Type& front() const {return *iterator(front_);}
    Value_Type& back() const {return *iterator(back_);}

    Value_Type& operator [] (size_t index) {
        return buffer_[index % capacity_];
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

    void resize(size_t capacity)
    {
        if (capacity < capacity_)
            return;
        auto * temp_buffer = new Value_Type [capacity];
        size_t i = 0;
        for (auto it = this->begin(); it != this->end(); it++) {
            temp_buffer[i] = *it;
            i++;
        }
        delete [] buffer_;
        buffer_ = temp_buffer;
        capacity_ = capacity;
        front_ = iterator(buffer_);
        back_ = iterator(buffer_ + size_);
    }

protected:
    Value_Type * buffer_;
    size_t size_ = 0;
    size_t capacity_ = 0;
private:
    iterator <Value_Type> front_{};
    iterator <Value_Type> back_{};

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