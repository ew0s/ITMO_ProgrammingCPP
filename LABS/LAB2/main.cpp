#include "complexNumb.h"

int main() {

    ComplexNumb numb1;
    ComplexNumb numb2;

    numb1.MultiplyByConst(2); // by constant
    numb1.print();

    numb2.Len(); // len

    numb1.MultiplyByComplex(numb2); // multi by complex numb
    numb1.print();

    numb1.summByComplex(numb2); // sum complex numbs
    numb1.print();

    numb1.print(); // print


    return 0;
}
