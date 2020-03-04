#pragma once

#include <iostream>

class ComplexNumb {

private:
    double m_real;
    double m_imaginary;

public:
    ComplexNumb ();

    ComplexNumb (double, double);

    ComplexNumb (const ComplexNumb &);

    void MultiplyByConst (double);

    void summByComplex (ComplexNumb&);

    void MultiplyByComplex (ComplexNumb&);

    void Len ();

    void print ();
};