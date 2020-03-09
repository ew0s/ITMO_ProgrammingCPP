#pragma once

#include "interface.h"


class Figure: public IGeoFig, public CVector2D, public IPhysObject, public IPrintable, public IgIDialogInitial, public BaseCObject{};


class Circle: public Figure {
public:

    Circle ();
    Circle (CVector2D&, double, double);

    double square() override ;
    double perimeter() override ;
    double mass() const override ;
    CVector2D position() override ;
    bool operator== (const IPhysObject& ob ) const override ;
    bool operator< (const IPhysObject& ob ) const override ;
    void draw() override ;
    void initFromDialog() override ;
    const char* classname() override ;
    unsigned int size() override ;

private:
    CVector2D m_center;
    double  m_radius;
    double m_mass;
    const char* m_classname;

};