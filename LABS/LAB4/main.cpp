#include <iostream>
#include <vector>
#include "Circle.h"
#include "interface.h"


int main () {


     Circle some1;
     some1.initFromDialog();

     Circle some2;
     some2.initFromDialog();

    (some1 < some2) ? std::cout << "YES" : std::cout << "NO";

    return 0;
}
