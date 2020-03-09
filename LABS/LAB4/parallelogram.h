#pragma once

#include "interface.h"
#include "Circle.h"


class Parallelogram: public Figure {
public:
    Parallelogram();

    double square() const override ;
    double perimeter() const override ;
    double mass() const override ;
    CVector2D position() const override ;
    bool operator== (const IPhysObject& ob ) const override ;
    bool operator< (const IPhysObject& ob ) const override ;
    void draw() const override ;
    void initFromDialog() override;
    const char* classname() const override ;
    unsigned int size() const override ;

private:
    CVector2D m_top1;
    CVector2D m_top2;
    CVector2D m_top3;
    CVector2D m_top4;
    double m_mass;
    const char* m_classname;
};