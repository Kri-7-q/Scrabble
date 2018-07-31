#ifndef TILEINFO_H
#define TILEINFO_H


class TileInfo
{
public:
    TileInfo();
    TileInfo(const unsigned char count, const unsigned char score);

    unsigned char pieceCount() const;
    unsigned char score() const;

private:
    unsigned char m_pieceCount;
    unsigned char m_score;
};

#endif // TILEINFO_H
