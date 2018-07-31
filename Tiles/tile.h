#ifndef TILE_H
#define TILE_H

#include <QChar>

class Tile
{
public:
    Tile();
    Tile(const QChar& letter, const quint8 score);

    QChar letter() const;
    void setLetter(const QChar &letter);
    quint8 score() const;
    void setScore(const quint8 &score);

private:
    QChar m_letter;
    quint8 m_score;
};

#endif // TILE_H
