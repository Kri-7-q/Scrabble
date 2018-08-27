#include "field.h"

// Standard constructor
Field::Field() :
    m_feature(None),
    m_bonus(0)
{

}

// Constructor with initialization.
Field::Field(const Feature feature, const quint8 bonus) :
    m_feature(feature),
    m_bonus(bonus)
{

}

// Copy constructor
Field::Field(const Field &field) :
    m_feature(field.m_feature),
    m_bonus(field.m_bonus)
{

}

// Get the field as a string.
QString Field::toString() const
{
    QString val("..");
    switch (m_feature) {
    case Word:
        val = QString("W").append(QString::number(m_bonus));
        break;
    case Letter:
        val = QString("L").append(QString::number(m_bonus));
        break;
    case Center:
        val = QString("()");
        break;
    default:
        break;
    }

    return val;
}

// Operator overload.
Field &Field::operator = (const Field &rhs)
{
    m_feature = rhs.m_feature;
    m_bonus = rhs.m_bonus;

    return *this;
}
