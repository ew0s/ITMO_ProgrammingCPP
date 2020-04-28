#include <iostream>
#include <fstream>


template <typename T>
struct elem {
    elem <T> * prev_ = nullptr;
    T numb_ = 0;
    elem <T> * next_ = nullptr;
};


template <typename T>
class list {

public:

    list ()
    {
        size_ = 0;

        std::ifstream fin ("input.txt");
        if (!fin)
            throw std::runtime_error("No such file");

        data_ = new elem <T>;

        T numb;
        while (fin >> numb)
            push(numb);
        fin.close();
    }


    ~list ()
    {
        delete [] data_;
    }


    void push(T numb)
    {
        if (size_ == 0)
        {
            data_->numb_ = numb;
            data_->next_ = nullptr;
            top = data_;
            tail = data_;
        }

        else
        {
            auto * new_elem = new elem <T>;
            new_elem->numb_ = numb;

            elem <T> * temp_ptr = data_;

            while (temp_ptr->next_ != nullptr)
                temp_ptr = temp_ptr->next_;

            temp_ptr->next_ = new_elem;
            temp_ptr->next_->prev_ = temp_ptr;

            tail = temp_ptr->next_;
        }

        size_++;
    }


    void print_list()
    {
        elem <T> * ptr = top;

        while (ptr->next_ != nullptr)
        {
            std::cout << ptr->numb_ << " ";
            ptr = ptr->next_;
        }
        std::cout << ptr->numb_ << std::endl;
    }


    void print_reverse()
    {
        elem <T> * ptr = tail;

        while (ptr->prev_ != nullptr)
        {
            std::cout << ptr->numb_ << " ";
            ptr = ptr->prev_;
        }
        std::cout << ptr->numb_ << std::endl;
    }

private:

    size_t size_;
    elem <T> * data_;

    elem <T> * top;
    elem <T> * tail;
};


int main() {

    list <float> new_list;

    new_list.print_list();
    new_list.print_reverse();

    return 0;
}
