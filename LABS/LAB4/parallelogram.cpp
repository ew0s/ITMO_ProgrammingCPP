#include "parallelogram.h"
#include <math.h>
#include <iostream>

Parallelogram::Parallelogram()
        :m_top1{}, m_top2{}, m_top3{}, m_top4{}, m_mass{}, m_classname("Parallelogram") {
}

double Parallelogram::square() const {
    CVector2D a, b;
    a.x = m_top2.x - m_top1.x, a.y = m_top2.y - m_top1.y;
    b.x = m_top3.x - m_top1.x, b.y = m_top3.y - m_top1.y;

    return abs(a.x * b.y - a.y * b.x);
}

double Parallelogram::perimeter() const {
    CVector2D a, b;
    a.x = m_top2.x - m_top1.x, a.y = m_top2.y - m_top1.y;
    b.x = m_top3.x - m_top1.x, b.y = m_top3.y - m_top1.y;

    return 2 * (sqrt(pow(a.x, 2) + pow(a.y, 2)) + sqrt(pow(b.x, 2) + pow(b.y, 2)));
}

double Parallelogram::mass() const {
    return m_mass;
}

CVector2D Parallelogram::position() const {
    CVector2D pos;
    pos = {(m_top4.x - m_top1.x) / 2, (m_top4.y - m_top1.y) / 2};
    return pos;
}

bool Parallelogram::operator==(const IPhysObject &ob) const {
    return this->mass() == ob.mass();
}

bool Parallelogram::operator<(const IPhysObject &ob) const {
    return this->mass() < ob.mass();
}

void Parallelogram::draw() const {
    std::cout << "/---------DRAW_PARALLELOGRAM---------/\n";
    std::cout << "Parallelogram:\n";
    std::cout << "First top is " << m_top1.x << " by OX and " << m_top1.y << " by OY\n";
    std::cout << "Second top is " << m_top2.x << " by OX and " << m_top2.y << " by OY\n";
    std::cout << "Third top is " << m_top3.x << " by OX and " << m_top3.y << " by OY\n";
    std::cout << "Fourth top is " << m_top4.x << " by OX and " << m_top4.y << " by OY\n";
    std::cout << "Weight is " << mass() << "\n";
    std::cout << "Classname is " << m_classname << '\n';
    std::cout << "Size in bytes is " << size() << '\n';
    std::cout << "/---------DRAW_PARALLELOGRAM---------/\n\n";
}

void Parallelogram::initFromDialog() {
    std::cout << "/---------Initialization_PARALLELOGRAM---------/\n";
    std::cout << "Enter Parallelogram's first top coordinates:\n";
    std::cin >> m_top1.x >> m_top1.y;
    std::cout << "Enter Parallelogram's second top coordinates:\n";
    std::cin >> m_top2.x >> m_top2.y;
    std::cout << "Enter Parallelogram's third top coordinates:\n";
    std::cin >> m_top3.x >> m_top3.y;
    m_top4 = {m_top1.x + m_top2.x + m_top3.x, m_top1.y + m_top2.y + m_top3.y};
    std::cout << "Enter Parallelogram's weight:\n";
    std::cin >> m_mass;
    std::cout << "/---------Initialization_PARALLELOGRAM---------/\n";
}

const char * Parallelogram::classname() const {
    return m_classname;
}

unsigned int Parallelogram::size() const {
    return sizeof(m_top1) * 4 + sizeof(m_mass) + sizeof(m_classname);
}