#pragma once

struct Vector{
    int x = 0;
    int y = 0;
};

class Triangle {
private:
    double m_x1, m_x2, m_x3;
    double m_y1, m_y2, m_y3;
    double m_square;

public:

    Triangle(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);

    friend bool operator > (Triangle &, Triangle &);

    friend bool operator < (Triangle &, Triangle &);

    friend bool operator == (Triangle &, Triangle &);

    friend bool operator != (Triangle &, Triangle &);

    Triangle operator + (Vector& vector);

    void square();

    void printCoordinates ();
};
