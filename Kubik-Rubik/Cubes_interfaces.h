#pragma once

#include <iostream>
#include <fstream>
#include <vector>


using std::vector;

class Sides_buffer;
class iRotate90;
class Side;


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


class Sides_buffer
{
public:
    Sides_buffer() = default;
    explicit Sides_buffer(const vector<Side*>& cube)
    {
        front_ = cube[0];
        back_ = cube[1];
        left_ = cube[2];
        right_ = cube[3];
        down_ = cube[4];
        up_ = cube[5];
    }
    Sides_buffer(Sides_buffer const &other)
    {
        buffer_.resize(5);
        for (int i = 0; i < 5; i++)
            buffer_[i] = other.buffer_[i];

        front_ = other.front_;
        back_ = other.back_;
        left_ = other.left_;
        right_ = other.right_;
        down_ = other.down_;
        up_ = other.up_;
    }
    ~Sides_buffer()
    {
        for (auto & i : buffer_)
        {
            delete i;
        }
        buffer_.clear();

        delete [] front_;
    }

    void compute_sides_buffer(const color side)
    {
        switch (side) {

            case RED: // front side in cube
            {
                buffer_[0] = front_; //  front
                buffer_[1] = left_; //   left
                buffer_[2] = right_; //  right
                buffer_[3] = up_;  //    up
                buffer_[4] = down_; //   down
                break;
            }
            case ORANGE: // back side in cube
            {
                buffer_[0] = back_; // front
                buffer_[1] = right_; //left
                buffer_[2] = left_; // right
                buffer_[3] = up_; //   up
                buffer_[4] = down_;//  down
                break;
            }
            case YELLOW: // left side in cube
            {
                buffer_[0] = left_; // front
                buffer_[1] = back_; // left
                buffer_[2] = front_; //right
                buffer_[3] = up_; //   up
                buffer_[4] = down_; // down
                break;
            }
            case GREEN: // right side in cube
            {
                buffer_[0] = right_; // front
                buffer_[1] = front_; // left
                buffer_[2] = back_; //  right
                buffer_[3] = up_; //    up
                buffer_[4] = down_; //  down
                break;
            }
            case BLUE: // up side in cube
            {
                buffer_[0] = down_; //  front
                buffer_[1] = left_; //  left
                buffer_[2] = right_; // right
                buffer_[3] = front_; //  up
                buffer_[4] = back_; // down
                break;
            }
            case WHITE: // down side in cube
            {
                buffer_[0] = up_; //  front
                buffer_[1] = left_; //  left
                buffer_[2] = right_; // right
                buffer_[3] = back_; // up
                buffer_[4] = front_; //  down
                break;
            }
        }
    }

private:
    vector <Side*> buffer_;

    Side * front_;
    Side * back_;
    Side * left_;
    Side * right_;
    Side * down_;
    Side * up_;
};


class iRotate90
{
public:

    iRotate90() = default;

    explicit iRotate90(const color what_side, vector<Side*>& cube)
    {
        Sides_buffer buffer_ (cube);
    }

    ~iRotate90() = default;
};

