#pragma once

#include <iostream>
#include <fstream>

enum color
{
    RED = '1', // FRONT
    ORANGE = '2', // BACK
    YELLOW = '3', // LEFT
    GREEN = '4', // RIGHT
    BLUE = '5', // DOWN
    WHITE = '6' // UP
};


// interface witch hold cube's side
class Side
{

public:

    Side() = default;

    Side(color const matrix[3][3])
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                matrix_[i][j] = matrix[i][j];
            }
    }

    Side (Side const &other)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                matrix_[i][j] = other.matrix_[i][j];
            }
    }

    Side& operator = (Side const &other)
    {
        Side copy (other);
        swap(*this, copy);
        return *this;
    }

    const color* operator * (Side const &other)
    {
        return *other.matrix_;
    }

    const color* operator [] (unsigned int const idx)
    {
        const color* copy = matrix_[idx];
        return copy;
    }

    ~Side() = default;

    void fill_with_color(color tmp_color)
    {
        for (auto & i : matrix_)
            for (auto & j : i)
                j = tmp_color;
    }

    color what_color()
    {
        return matrix_[1][1];
    }

    void print_side()
    {
        for (auto & i : matrix_)
        {
            for (auto & j : i)
            {
                std::cout << static_cast<char>(j) << ' ';
            }
            std::cout << std::endl;
        }
    }


protected:
    color matrix_ [3][3]{};

    static void swap (Side &lValue, Side &rValue)
    {
        std::swap(lValue.matrix_, rValue.matrix_);
    }
};