#include "Cube.h"
#include <fstream>
#include <iostream>


int main()
{
    std::ifstream fin ("input.txt");
    std::ofstream fOut ("output.txt");
    iCube some_cube;
    some_cube.write(fin);

    some_cube.iRotate90(BLUE);

    some_cube.read(fOut);

    return 0;
}