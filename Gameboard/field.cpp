#include "field.h"

// Standard constructor
Field::Field(const bool isCenter) :
    m_wordBonus(0),
    m_letterBonus(0),
    m_isCenter(isCenter)
{

}

// Constructor with initialization.
Field::Field(const quint8 wordBonus, const quint8 letterBonus) :
    m_wordBonus(wordBonus),
    m_letterBonus(letterBonus),
    m_isCenter(false)
{

}

// Copy constructor
Field::Field(const Field &field) :
    m_wordBonus(field.m_wordBonus),
    m_letterBonus(field.m_letterBonus),
    m_isCenter(false)
{

}

// Get the field as a string.
QString Field::toString() const
{
    if (m_wordBonus > 0) {
        return QString("W").append(QString::number(m_wordBonus));
    }
    if (m_letterBonus > 0) {
        return QString("L").append(QString::number(m_letterBonus));
    }
    if (m_isCenter) {
        return QString("()");
    }

    return QString("..");
}

// Operator overload.
Field &Field::operator = (const Field &rhs)
{
    m_wordBonus = rhs.m_wordBonus;
    m_letterBonus = rhs.m_letterBonus;

    return *this;
}
