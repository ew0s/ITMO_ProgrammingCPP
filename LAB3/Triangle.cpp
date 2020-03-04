#include "Triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    m_x1 = x1, m_y1 = y1;
    m_x2 = x2, m_y2 = y2;
    m_x3 = x3, m_y3 = y3;
    m_square = abs((m_x2 - m_x1) * (m_y3 - m_y1) - (m_x3 - m_x1) * (m_y2 - m_y1)) / 2;
}

bool operator == (Triangle &trig1, Triangle &trig2) {
    return trig1.m_square == trig2.m_square;
}

bool operator != (Triangle &trig1, Triangle &trig2){
    return !(trig1 == trig2);
}

bool operator < (Triangle &trig1, Triangle &trig2) {
    return trig1.m_square < trig2.m_square;
}

bool operator > (Triangle &trig1, Triangle &trig2) {
    return trig1.m_square > trig2.m_square;
}

Triangle Triangle::operator+(Vector &vector) {
    m_x1 += vector.x;
    m_x2 += vector.x;
    m_x3 += vector.x;

    m_y1 += vector.y;
    m_y2 += vector.y;
    m_y3 += vector.y;

    return Triangle(m_x1, m_y1, m_x2, m_y2, m_x3, m_y3);

}

void Triangle::square(){
    std::cout << "The square is " << m_square << "\n";
}

void Triangle::printCoordinates() {
    std::cout << "First top " << m_x1 << " " << m_y1 << "\n";
    std::cout << "Second top " << m_x2 << " " << m_y2 << "\n";
    std::cout << "First top " << m_x3 << " " << m_y3 << "\n";

}

