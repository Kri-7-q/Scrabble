#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point();
    Point(const int x, const int y);

    int x() const;
    void setX(int x);
    int y() const;
    void setY(int y);

private:
    int m_x;
    int m_y;
};

#endif // POINT_H
