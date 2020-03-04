#pragma once
#include <vector>

class Array{

private:
    std::vector <int> m_arr;

public:
    Array (std::vector <int> = {});

    friend Array operator + (Array&, Array&);

    friend bool operator == (Array&, Array&);

    friend bool operator != (Array&, Array&);

    friend bool operator > (Array&, Array&);

    friend bool operator < (Array&, Array&);

    void print();
};