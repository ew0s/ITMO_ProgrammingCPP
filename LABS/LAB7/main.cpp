#include <iostream>
#include "Circular_Buffer.h"
#include <vector>


int main()
{
    Circular_Buffer <int> buffer(3);
    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);


    std::vector <int> a = {1, 2, 3};
    a.resize(3);
    for (auto it = a.begin(); it != a.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
    a.resize(2);
    for (auto it = a.begin(); it != a.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
    return 0;
}