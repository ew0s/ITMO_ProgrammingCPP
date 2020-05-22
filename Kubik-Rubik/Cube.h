#pragma once

#include <fstream>
#include <vector>
#include <exception>
#include <map>
#include <iostream>


using std::vector;

enum color
{
    RED = '1',
    ORANGE = '2',
    YELLOW = '3',
    GREEN = '4',
    BLUE = '5',
    WHITE = '6'
};

typedef vector<vector<color>> side_vector;
typedef vector<vector<vector<color>>> sides_matrix;
typedef vector<vector<color>>*  pointer_on_side;


class iCube
{
public:
    iCube ()
    {
        sides_.resize(6, side_vector (3, vector<color> (3)));
        front_ = &sides_[0];
        back_ = &sides_[1];
        left_ = &sides_[2];
        right_ = &sides_[3];
        up_ = &sides_[4];
        down_ = &sides_[5];
    }
    ~iCube() = default;

    void write(std::ifstream&  input)
    {
        if (!input)
            throw std::runtime_error("no input file");

        sides_.resize(6, side_vector (3, vector<color> (3)));
        for (int side = 0; side != 6; side++)
            for (int row = 0; row != 3; row++)
            {
                std::string tmp_row;
                input >> tmp_row;
                sides_[side][row][0] = static_cast<color>(tmp_row[0]);
                sides_[side][row][1] = static_cast<color>(tmp_row[1]);
                sides_[side][row][2] = static_cast<color>(tmp_row[2]);
            }
        input.close();
    }

    void read(std::ofstream& output) const
    {
        if (!output)
            throw std::runtime_error("no input file");

        for (int side = 0; side != 6; side++)
        {
            for (int row = 0; row != 3; row++)
            {
                output << static_cast<int>(sides_[side][row][0] - '0');
                output << static_cast<int>(sides_[side][row][1] - '0');
                output << static_cast<int>(sides_[side][row][2] - '0');
                output << std::endl;
            }
        }
    }

    void show_cube () const
    {
        std::ofstream output ("output.txt");
        for (auto side = sides_.begin(); side != sides_.end(); side++)
        {
            for (auto row = side->begin(); row != side->end(); row++)
            {
                for (auto column = row->begin(); column != row->end(); column++)
                {
                    output << static_cast<char>(*column) << ' ';
                }
                output << std::endl;
            }
            output << std::endl;
        }
        output.close();
    }

    bool iCorrect_Cube() // check of correct invariant of the cube
    {
        std::map <color, int> statements;
        for (int side = 0; side < 6; side++)
        {
            for (int row = 0; row < 3; row++)
            {
                statements[sides_[side][row][0]]++;
                statements[sides_[side][row][1]]++;
                statements[sides_[side][row][2]]++;
            }
        }

        for (auto & statement : statements)
        {
            if (statement.second != 9)
                return false;
        }

        return true;
    }

    void iRotate90(const color side)
    {
        /*
         * front idx = 0
         * left idx = 1
         * right idx = 2
         * up idx = 3
         * down idx = 4
         */

        vector <pointer_on_side> sides_buffer (5, pointer_on_side(3));
        compute_sides_buffer(side, sides_buffer);

        vector <color*> outside_circle;
        // calculate up side's blocks in buffer
        vector <vector<color>> temp = *sides_buffer[3];
        for (auto it = temp[2].begin(); it != temp[2].end(); it++)
            outside_circle.push_back(&*it);
        

        for (auto it = outside_circle.begin(); it != outside_circle.end(); it++)
            std::cout << static_cast<char>(**it) << ' ';
    }



private:
    sides_matrix sides_;
    side_vector * front_;
    side_vector * left_;
    side_vector * back_;
    side_vector * right_;
    side_vector * up_;
    side_vector * down_;

    /*
    RED = 1 = FRONT,
    ORANGE = 2 = BACK,
    YELLOW = 3 = LEFT,
    GREEN = 4 = RIGHT,
    BLUE = 5 = UP,
    WHITE = 6 = DOWN*/

    void compute_sides_buffer(const color side, vector<pointer_on_side> &buffer)
    {
        switch (side) {

            case RED: // front side in cube
            {
                buffer[0] = front_; //  front
                buffer[1] = left_; //   left
                buffer[2] = right_; //  right
                buffer[3] = up_;  //    up
                buffer[4] = down_; //   down
                break;
            }
            case ORANGE: // back side in cube
            {
                buffer[0] = back_; // front
                buffer[1] = right_; //left
                buffer[2] = left_; // right
                buffer[3] = up_; //   up
                buffer[4] = down_;//  down
                break;
            }
            case YELLOW: // left side in cube
            {
                buffer[0] = left_; // front
                buffer[1] = back_; // left
                buffer[2] = front_; //right
                buffer[3] = up_; //   up
                buffer[4] = down_; // down
                break;
            }
            case GREEN: // right side in cube
            {
                buffer[0] = right_; // front
                buffer[1] = front_; // left
                buffer[2] = back_; //  right
                buffer[3] = up_; //    up
                buffer[4] = down_; //  down
                break;
            }
            case BLUE: // up side in cube
            {
                buffer[0] = up_; //    front
                buffer[1] = left_; //  left
                buffer[2] = right_; // right
                buffer[3] = back_; //  up
                buffer[4] = front_; // down
                break;
            }
            case WHITE: // down side in cube
            {
                buffer[0] = down_; //  front
                buffer[1] = left_; //  left
                buffer[2] = right_; // right
                buffer[3] = front_; // up
                buffer[4] = back_; //  down
                break;
            }
        }
    }
};
