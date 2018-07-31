#include "point.h"

// Standard constructor
Point::Point() :
    m_x(0),
    m_y(0)
{

}

// Constructor
// Get a initialized Point object.
Point::Point(const int x, const int y) :
    m_x(x),
    m_y(y)
{

}

int Point::x() const
{
    return m_x;
}

void Point::setX(int x)
{
    m_x = x;
}

int Point::y() const
{
    return m_y;
}

void Point::setY(int y)
{
    m_y = y;
}
