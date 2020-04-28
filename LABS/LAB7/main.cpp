#include <iostream>

#include "Circular_buffer.h"

int main() {

    CCircular_Buffer<int> buffer(3);

    buffer.push_front(3);
    buffer.push_front(2);
    buffer.push(3, 1);

    for (int i = 0; i < buffer.size(); i++){
        std::cout << buffer[i] << " ";
    }
    return 0;
}
