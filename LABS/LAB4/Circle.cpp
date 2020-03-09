#include "Circle.h"
#include <math.h>
#include <iostream>

Circle::Circle():
    m_center{}, m_radius{}, m_mass{}, m_classname("Circle"){
}

Circle::Circle(CVector2D &center, double radius, double mass):
    m_center(center), m_radius(radius), m_mass(mass), m_classname("Circle"){
}

double Circle::square() const {
    return m_radius * m_radius * M_PI;
}

double Circle::perimeter() const {
    return 2 * M_PI * m_radius;
}

double Circle::mass() const {
    return m_mass;
}

CVector2D Circle::position() const {
    CVector2D pos{m_center.x, m_center.y};
    return pos;
}

bool Circle::operator==(const IPhysObject &ob) const {
    return this->mass() == ob.mass();
}

bool Circle::operator<(const IPhysObject &ob) const {
    return this->mass() < ob.mass();
}

void Circle::draw() const {
    std::cout << "/---------DRAW---------/\n";
    std::cout << "Circle:\n";
    std::cout << "Center is " << m_center.x << " by OX and " << m_center.y << " by OY\n";
    std::cout << "Radius is " << m_radius << "\n";
    std::cout << "Weight is " << mass() << "\n";
    std::cout << "Classname is " << m_classname << '\n';
    std::cout << "Size in bytes is " << size() << '\n';
    std::cout << "/---------DRAW---------/\n\n";
}

void Circle::initFromDialog() {
    std::cout << "/---------Initialization---------/\n";
    std::cout << "Enter Circle's center coordinates\n";
    CVector2D center;
    std::cin >> center.x >> center.y;
    std::cout << "Enter Circle's radius length\n";
    double radius;
    std::cin >> radius;
    std::cout << "Enter Circle's weight\n";
    double mass;
    std::cin >> mass;
    m_mass = abs(mass);
    m_radius = abs(radius);
    m_center = center;
    std::cout << "/---------Initialization---------/\n\n";
}

const char * Circle::classname() const {
    return m_classname;
}

unsigned int Circle::size() const {
    return sizeof(m_center) + sizeof(m_radius) + sizeof(m_mass) + sizeof(m_classname);
}

