#include <iostream>
#include "List.h"

int main() {

    List someList;

    someList.push(1);
    someList.push(2);
    someList.push(3);
    someList.push(4);

    std::cout << someList.last() << "last element\n";

    someList.swap();

    std::cout << someList.get(-1) << " is (-1) element in linked list\n";

    return 0;
}