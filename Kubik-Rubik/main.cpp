#include "Cube.h"

#include <iostream>
#include <fstream>


int main()
{
    std::ifstream fin ("input.txt");
    std::ofstream fOut ("output.txt");
    Cube some_cube1;

    some_cube1.write(fin);
    some_cube1.read(fOut);

    some_cube1.iCorrectCube() ? std::cout << "YES\n\n" : std::cout << "NO\n\n";

    std::cout << some_cube1;

    return 0;
}