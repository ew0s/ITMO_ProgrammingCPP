#pragma once

#include <vector>
#include <fstream>
#include <exception>
#include <map>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <random>
#include <iostream>


enum color
{
    WHITE = '1',
    BLUE = '2',
    PINK = '3',
    GREEN = '4',
    RED = '5',
    BLACK = '6'
};

using std::vector;

class iCube
{
public:
    iCube ()
    {
        sides_.resize(6, vector<vector<color>>(3, vector<color> (3)));
        iGenerateRandom_Cube();
    }
    ~iCube() = default;

    void show_cube ()
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

    void iGenerateRandom_Cube ()
    {
        std::map <color, int> colors;

        for (int side = 0; side != 6; side++)
        {
            for (int row = 0; row != 3; row++)
            {
                for (int column = 0; column != 3; column++)
                {
                    color temp_block = generateRandomNumber_for_cube();
                    color block = temp_block;

                    if (colors[block] < 9)
                    {
                        sides_[side][row][column] = block;
                        colors[block]++;
                    }
                }
            }
        }

        int a = 10;
    }

    void write(std::ifstream& input)
    {
        if (!input)
            throw std::runtime_error("no input file");

        sides_.resize(6, vector<vector<color>>(3, vector<color> (3)));
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

    void read(std::ofstream& output)
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



private:

    void iFillCube(std::stack <color> statements)
    {
        for (int side = 0; side != 6; side++)
            for (int row = 0; row != 3; row++)
                for (int column = 0; column != 3; column++)
                {
                    color block = statements.top();
                    statements.pop();
                    sides_[side][row][column] = block;
                }
    }

    static color generateRandomNumber_for_cube ()
    {
        srandom(static_cast<unsigned int>(time(nullptr)));
        return static_cast<color>(static_cast<char>((random() % (54 - 49 + 1) + 49)));

    }


    vector <vector<vector<color>>> sides_;

};
