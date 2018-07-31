#ifndef GAMEBORAD_H
#define GAMEBORAD_H

#include <QRect>

template<class T>
class Gameborad
{
public:
    Gameborad(const int width, const int height);
    ~Gameborad();

    void setField(const T* field, const int x, const int y);
    T* fieldAt(const int x, const int y) const;

protected:
    void mirrorDiagonalToRightUp(const QRect& rect);

private:
    T* m_board;
    int m_width;
    int m_height;
};

#endif // GAMEBORAD_H
