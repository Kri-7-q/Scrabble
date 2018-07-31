#include "field.h"

// Standard constructor
Field::Field()
{

}

// Constructor with initialization.
Field::Field(const unsigned char wordBonus, const unsigned char letterBonus) :
    m_wordBonus(wordBonus),
    m_letterBonus(letterBonus)
{

}
