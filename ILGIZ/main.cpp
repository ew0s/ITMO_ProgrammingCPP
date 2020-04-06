#include <iostream>
#include "List.h"

int main() {

    List someList;

    someList.push(5);
    std::cout << someList.last();
}