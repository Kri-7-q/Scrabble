#include "tileinfo.h"

// Standard constructor
TileInfo::TileInfo() :
    m_pieceCount(0),
    m_score(0)
{

}

// Constructor with initialization.
TileInfo::TileInfo(const unsigned char count, const unsigned char score) :
    m_pieceCount(count),
    m_score(score)
{

}

unsigned char TileInfo::pieceCount() const
{
    return m_pieceCount;
}

unsigned char TileInfo::score() const
{
    return m_score;
}
