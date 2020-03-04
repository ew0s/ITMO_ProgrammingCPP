#include "complexNumb.h"
#include <iostream>
#include <cmath>


ComplexNumb::ComplexNumb (){

    m_real = 0.0;
    m_imaginary = 0.0;
}

ComplexNumb::ComplexNumb(double real, double imaginary) {
    m_real = real;
    m_imaginary = imaginary;
}

ComplexNumb::ComplexNumb(const ComplexNumb &copy) {

    m_imaginary = copy.m_imaginary;
    m_real = copy.m_real;
}

void ComplexNumb::MultiplyByConst(double numb) {

    m_real *= numb;
    m_imaginary *= numb;
}

void ComplexNumb::summByComplex(ComplexNumb &numb) {

    m_real += numb.m_real;
    m_imaginary += numb.m_imaginary;
}

void ComplexNumb::MultiplyByComplex(ComplexNumb &numb) {

    double temp = m_real;

    m_real = (m_real * numb.m_real - m_imaginary * numb.m_imaginary);

    m_imaginary = (temp * numb.m_imaginary + m_imaginary * numb.m_real);
}


void ComplexNumb::Len() {

    std::cout << "len is " <<  sqrt(pow(m_real, 2) + pow(m_imaginary, 2)) << "\n\n";
}


void ComplexNumb::print () {

    if (m_imaginary >= 0)
        std::cout << m_real << " + " << m_imaginary << "i";
    else
        std::cout << m_real << " - " << m_imaginary * -1 << "i";
    std::cout << "\n\n";
}

