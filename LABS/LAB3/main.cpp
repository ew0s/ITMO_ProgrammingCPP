#include <iostream>
#include <vector>
#include "Array.h"
#include "Triangle.h"

int main() {

    std::cout << "//------------------------EX3------------------------//\n";

    Triangle trig1 {0, 0, 3, 0, 0, 4};
    Triangle trig2 {0, 0, 4, 0, 0, 3};

    // What Square ?
    trig1.square();

    // Is squares equal ?
    (trig1 == trig2) ? std::cout << "Squares are the same\n" : std::cout << "Squares are not the same\n";
    (trig1 != trig2) ? std::cout << "Squares are not the same\n" : std::cout << "Squares are the same\n";

    // Bigger or Smaller ?
    (trig1 > trig2) ? std::cout << "First is bigger\n" : std::cout << "Second is bigger\n";

    //sum
    Vector vec {1, 1};
    Triangle trig3 = trig1 + vec;
    trig3.printCoordinates();

    std::cout << "//------------------------EX6------------------------//\n";

    std::vector <int> a {1, 2, 3, 4, 5};
    std::vector <int> b {6, 7, 8, 9, 10};

    Array array1 {a};
    Array array2 {b};

    //Is arrays equal ?
    (array1 == array2) ? std::cout << "Equal\n" : std::cout << "Not Equal\n";

    //Bigger or Smaller ?
    (array1 > array2) ? std::cout << "First is bigger\n" : std::cout << "Second is bigger\n";

    //Sum
    Array array3 = array1 + array2;
    array3.print();

    return 0;
}
