#include "tile.h"


// Standard Constructor
Tile::Tile() :
    m_letter('-'),
    m_score(0)
{

}

// Constructer with initialization.
Tile::Tile(const QChar &letter, const quint8 score) :
    m_letter(letter),
    m_score(score)
{

}

QChar Tile::letter() const
{
    return m_letter;
}

void Tile::setLetter(const QChar &letter)
{
    if (letter.isLetter() || letter == '?') {
        m_letter = letter.toUpper();
    }
}

quint8 Tile::score() const
{
    return m_score;
}

void Tile::setScore(const quint8 &score)
{
    m_score = score;
}
