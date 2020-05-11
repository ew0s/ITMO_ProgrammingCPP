#include <iostream>
#include "Circular_Buffer.h"

int main()
{
    Circular_Buffer <int> buffer(3);
    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);
    buffer.pop_front();
    for (auto it = buffer.begin(); it != buffer.end(); it++)
        std::cout << *it << " ";

    return 0;
}