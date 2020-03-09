#include <iostream>
#include <vector>
#include "Circle.h"
#include "interface.h"


int main () {


     CVector2D newFig {0, 0};
     Circle some {newFig, 3, 4};
     some.draw();


}
