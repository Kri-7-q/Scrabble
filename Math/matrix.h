#ifndef MATRIX_H
#define MATRIX_H

/*
 * Class Matrix
 * ---------------
 * Matrix is a template class and can take any type for its fields.
 * But a field MUST have some features:
 *  - copy constructor
 *  - toString() method
 */

#include <QPoint>
#include <QSize>
#include <QString>

template<class T>
class Matrix
{
public:
    enum CopyArea { LeftTop, RightBottom, LeftBottom, RightTop, HorzTop, HorzBottom, VertLeft, VertRight };

    Matrix(const int width, const int height);
    Matrix(const QSize& size);
    ~Matrix();

    void setField(const T field, const int x, const int y);
    T field(const int x, const int y) const;

    Matrix section(const int x, const int y, const int width, const int height) const;
    Matrix section(const QPoint& leftTop, QSize& size) const;

    bool mirrorCopy(const CopyArea area);

    QString toString() const;

protected:
    Matrix(const QPoint& leftTop, const QSize& size, const QSize &origin, T* matrix);

    bool copyAxisLeftTopToRightBottom(const CopyArea area);
    bool copyAxisLeftBottomToRightTop(const CopyArea area);
    bool copyAxisHorizontal(const CopyArea area);
    bool copyAxisVertical(const CopyArea area);

private:
    void initialize(const int width, const int height);

private:
    QPoint m_leftTop;
    QSize m_size;
    QSize m_originSize;
    T* m_matrix;
    bool m_isSection;
};

#endif // MATRIX_H
