#ifndef MATRIX_H
#define MATRIX_H

#include <QPoint>
#include <QSize>

template<class T>
class Matrix
{
public:
    enum Axis { LeftTop, RightBottom, LeftBottom, RightTop, Horizontal, Vertical };

    Matrix(const int width, const int height);
    Matrix(const QSize& size);

    void setField(const T* field, const int x, const int y);
    T* field(const int x, const int y) const;

    Matrix section(const int x, const int y, const int width, const int height) const;
    Matrix section(const QPoint& leftTop, QSize& size) const;

protected:
    Matrix(const QPoint& leftTop, const QSize& size, const QSize &origin, T* matrix);

private:
    QPoint m_leftTop;
    QSize m_size;
    QSize m_originSize;
    T* m_matrix;
    bool m_isSection;
};

#endif // MATRIX_H
