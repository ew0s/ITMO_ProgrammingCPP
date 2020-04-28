template <typename T>
CCircular_Buffer<T>::CCircular_Buffer():
        size_(0),
        capacity_(0),
        buffer_(nullptr),
        head_(0),
        tail_(0){
}


template <typename T>
CCircular_Buffer<T>::CCircular_Buffer(unsigned int capacity):
        size_(0),
        capacity_(capacity),
        buffer_(new T [capacity]),
        head_(0),
        tail_(0){
}


template <typename T>
CCircular_Buffer<T>::~CCircular_Buffer()
{
    delete [] buffer_;
}


template <typename T>
void CCircular_Buffer<T>::increment_head()
{
    head_++;
    size_--;
    if (head_ == capacity_)
        head_ = 0;
}


template <typename T>
void CCircular_Buffer<T>::increment_tail()
{
    tail_++;
    size_++;
    if (tail_ == capacity_)
        tail_ = 0;
}


template <typename T>
void CCircular_Buffer<T>::decrement_tail()
{
    tail_--;
    size_--;
    if (tail_ == -1)
        tail_ = capacity_ - 1;
}


template <typename T>
void CCircular_Buffer<T>::push_back(T numb)
{
    if (!size_)
    {
        buffer_[tail_] = numb;
        tail_ == head_;
        size_++;
    }

    else if (size_ != capacity_)
    {
        increment_tail();
        buffer_[tail_] = numb;
    }

    else
    {
        increment_tail();
        increment_head();
        buffer_[tail_] = numb;
    }
}


template <typename T>
void CCircular_Buffer<T>::pop_back()
{
    if (!size_)
        throw std::invalid_argument("The circular buffer is empty");

    else if (tail_ == head_)
        size_ = 0;

    else
        decrement_tail();
}


template <typename T>
void CCircular_Buffer<T>::pop_front()
{
    if (!size_)
        throw std::invalid_argument("The circular buffer is empty");

    else if (head_ == tail_)
        size_ = 0;

    else
        increment_head();
}


template <typename T>
void CCircular_Buffer<T>::push_front(T numb)
{
    if (!size_)
    {
        buffer_[head_] = numb;
        size_++;
        return;
    }

    else if (size_ != capacity_)
        increment_tail();

    for (int iterator = tail_; iterator > head_; iterator--)
    {
        buffer_[iterator] = buffer_[iterator - 1];
    }

    buffer_[head_] = numb;
}


template <typename T>
T CCircular_Buffer<T>::front() const
{
    if (!size_)
        throw std::invalid_argument("The circular buffer is empty");
    return buffer_[head_];
}


template <typename T>
T CCircular_Buffer<T>::back() const
{
    if (!size_)
        throw std::invalid_argument("The circular buffer is empty");
    return buffer_[tail_];
}


template <typename T>
T& CCircular_Buffer<T>::operator[](int idx) const
{
    if (idx < 0 || idx >= size_)
        throw std::invalid_argument("Invalid index");

    return buffer_[(head_ + idx) % capacity_];
}


template <typename T>
void CCircular_Buffer<T>::push(int index, T numb)
{
    if (index < 0 || index >= capacity_ || !size_)
        throw std::invalid_argument("Invalid index");

    if (size_ != capacity_)
        increment_tail();

    for (int iterator = tail_; iterator > index; iterator--)
    {
        buffer_[iterator] = buffer_[iterator - 1];
    }

    buffer_[index] = numb;
}


template <typename T>
int CCircular_Buffer<T>::size() const
{
    return size_;
}