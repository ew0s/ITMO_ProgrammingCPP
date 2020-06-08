#pragma once

#include <fstream>
#include <vector>
#include <exception>
#include <map>
#include <iostream>
#include "Cubes_interfaces.h"


using std::vector;

class Cube
{
public:
    Cube ()
    {
        sides_.resize(6);
        int i = 0;
        for (char fill_with = '1'; fill_with <= '6'; fill_with++)
        {
            sides_[i].fill_with_color(static_cast<color>(fill_with));
            i++;
        }

        front_ = &sides_[0];
        back_ = &sides_[1];
        left_ = &sides_[2];
        right_ = &sides_[3];
        down_ = &sides_[4];
        up_ = &sides_[5];
    }

    Cube& operator = (const Cube& other)
    {
        Cube copy (other);
        swap(*this, copy);
        return *this;
    }

    ~Cube() = default;


    friend std::ostream & operator << (std::ostream &out, Cube & tmp_cube);

    void read(std::ofstream & out)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    out << static_cast<char>(sides_[i][j][k]);
                }
                out << std::endl;
            }
        }
    }

    void write(std::ifstream & input)
    {
        color readable_matrix[3][3];
        std::string line;
        for (int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                input >> line;
                for (int k = 0; k < 3; k++)
                {
                    readable_matrix[j][k] = static_cast<color>(line[k]);
                }
            }
            sides_[i] = readable_matrix;
        }
    }

    //Check the correct state of the cube
    //from the point of view of it's invariants
    bool iCorrectCube()
    {
        // check that there is all 9 colors of each type in the cube
        std::map <color, int> colors;

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    colors[sides_[i][j][k]]++;
                    if (colors[sides_[i][j][k]] > 9)
                        return false;
                }
            }
        }

        colors.clear();

        // check that all middle blocks on each side have different color
        for (int i = 0; i < 6; i++)
        {
            colors[sides_[i][1][1]]++;
            if (colors[sides_[i][1][1]] > 1)
                return false;
        }

        // check all corner blocks on the front side
        // according to each corner block has different color on each side
        if (front_[0][0][0] != up_[0][2][0] && front_[0][0][0] != left_[0][0][2])
        {
            if (front_[0][0][2] != up_[0][2][2] && front_[0][0][2] != right_[0][0][0])
            {
                if (front_[0][2][0] != left_[0][2][2] && front_[0][2][0] != down_[0][0][0])
                {
                    if (front_[0][2][2] != down_[0][0][2] && front_[0][2][2] != right_[0][2][0])
                    {
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }

        // check all corner blocks on the back side
        // according to each corner block has different color on each side
        if (back_[0][0][0] != right_[0][0][2] && back_[0][0][0] != up_[0][0][2])
        {
            if (back_[0][0][2] != left_[0][0][0] && back_[0][0][2] != up_[0][0][0])
            {
                if (back_[0][2][0] != right_[0][2][2] && back_[0][2][0] != down_[0][2][2])
                {
                    if (back_[0][2][2] != left_[0][2][0] && back_[0][2][2] != down_[0][2][0])
                    {
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }

        // check front's side's middle - side blocks
        if (front_[0][1][0] != left_[0][1][2])
        {
            if (front_[0][0][1] != up_[0][2][1])
            {
                if (front_[0][1][2] != right_[0][1][0])
                {
                    if (front_[0][2][1] != down_[0][0][1]){
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }

        // check up's side's middle - side blocks
        // knows that we've already checked middle - side blocks on the front side
        if (up_[0][0][1] != back_[0][0][1])
        {
            if (up_[0][1][0] != left_[0][0][1])
            {
                if (up_[0][1][2] != right_[0][0][1]){
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }

        // check right's side's middle - side blocks
        // knows that we've already checked middle - side blocks on the
        // front and up sides
        if (right_[0][2][1] != down_[0][1][2])
        {
            if (right_[0][1][2] != back_[0][1][0]){
            } else {
                return false;
            }
        } else {
            return false;
        }

        // check left's side's middle - side blocks
        // knows that we've already checked middle - side blocks on the
        // front, up and right sides
        if (left_[0][1][0] != back_[0][1][2])
        {
            if (left_[0][2][1] != down_[0][1][0]){
            } else {
                return false;
            }
        } else {
            return false;
        }

        // check back's side's middle - side blocks
        // knows that we've already checked middle - side blocks on the
        // front, up, right and left sides
        if (back_[0][2][1] != down_[0][2][1]){
        } else {
            return false;
        }

        return true;
    }

    void rotate90 (const color what_side)
    {
        vector <Side*> tmp_buffer (6);
        for (int i = 0; i < 6; i++)
            tmp_buffer[i] = &sides_[i];
        iRotate90 a (what_side, tmp_buffer);


        std::cout << 

        for (int i = 0; i < tmp_buffer.size(); i++)
            delete tmp_buffer[i];
        tmp_buffer.clear();
    }


private:
    vector <Side> sides_ {};

    static void swap (Cube &lValue, Cube &rValue) noexcept
    {
        std::swap(lValue.sides_, rValue.sides_);
    }

    Side * front_;
    Side * back_;
    Side * left_;
    Side * right_;
    Side * down_;
    Side * up_;

    /*
    RED = 1 = FRONT,
    ORANGE = 2 = BACK,
    YELLOW = 3 = LEFT,
    GREEN = 4 = RIGHT,
    BLUE = 5 = DOWN,
    WHITE = 6 = UP
     */
};


std::ostream & operator << (std::ostream &out, Cube & tmp_cube)
{
    // Up side
    for (int i = 0; i < 3; i++)
    {
        out << std::setw(7);
        for (int j = 0; j < 3; j++)
        {
            out << static_cast<char>(tmp_cube.sides_[5][i][j]) << ' ';
        }
        out << std::endl;
    }

    // left, front, right, back
    int sides_sequence[4] = {2, 0, 3, 1};

    for (int i = 0; i < 3; i++)
    {
        for (int j : sides_sequence)
        {
            for (int k = 0; k < 3; k++)
            {
                out << static_cast<char>(tmp_cube.sides_[j][i][k]) << ' ';
            }
        }
        out << std::endl;
    }

    // down
    for (int i = 0; i < 3; i++)
    {
        out << std::setw(7);
        for (int j = 0; j < 3; j++)
        {
            out << static_cast<char>(tmp_cube.sides_[4][i][j]) << ' ';
        }
        out << std::endl;
    }

    return out;
}
