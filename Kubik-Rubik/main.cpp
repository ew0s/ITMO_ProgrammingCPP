#include "Cube.h"
#include <fstream>
#include <iostream>


int main()
{
    std::ifstream fin ("input.txt");
    std::ofstream fOut ("output.txt");
    iCube some_cube;
    some_cube.iGenerateRandom_Cube();
    //some_cube.write(fin);
    some_cube.read(fOut);
}