#include "matrix.h"

// Constructor
// Creates a matrix of given size.
template<class T>
Matrix<T>::Matrix(const int width, const int height) :
    m_leftTop(0, 0),
    m_size(width, height),
    m_originSize(width, height),
    m_isSection(false)
{
    initialize(width, height);
}

// Constructor
// Creates a matrix of given size.
template<class T>
Matrix<T>::Matrix(const QSize &size) :
    m_leftTop(0, 0),
    m_size(size),
    m_originSize(size),
    m_isSection(false)
{
    initialize(size.width(), size.height());
}

// Destructor
// Delete all data from heap.
template<class T>
Matrix<T>::~Matrix()
{
    if (! m_isSection) {
        delete [] m_matrix;
    }
}

// Set a field at a given position in the matrix.
template<class T>
void Matrix<T>::setField(const T field, const int x, const int y)
{
    int index = m_originSize.width() * (y + m_leftTop.y()) + x + m_leftTop.x();
    m_matrix[index] = field;
}

// Get the field at a given position from the matrix.
template<class T>
T Matrix<T>::field(const int x, const int y) const
{
    int index = m_originSize.width() * (y + m_leftTop.y()) + x + m_leftTop.x();

    return m_matrix[index];
}

// Copy an area of the matrix like a mirror.
template<class T>
bool Matrix<T>::mirrorCopy(const Matrix::CopyArea area)
{
    switch (area) {
    case RightTop:
    case LeftBottom:
        copyAxisLeftTopToRightBottom(area);
        break;
    case LeftTop:
    case RightBottom:
        copyAxisLeftBottomToRightTop(area);
        break;
    case HorzTop:
    case HorzBottom:
        copyAxisHorizontal(area);
        break;
    case VertLeft:
    case VertRight:
        copyAxisVertical(area);
        break;
    default:
        break;
    }

    return true;
}

// Get a string reprasentation of the matrix.
template<class T>
QString Matrix<T>::toString() const
{
    QString matrix;
    for (int y=0; y<m_size.height()-m_leftTop.y(); ++y) {
        for (int x=0; x<m_size.width()-m_leftTop.x(); ++x) {
            T f = field(x, y);
            matrix.append(f.toString()).append(' ');
        }
        matrix.append('\n');
    }

    return matrix;
}

// Get a section of a matrix.
template<class T>
Matrix<T> Matrix<T>::section(const QPoint &leftTop, QSize &size) const
{
    return Matrix(leftTop, size, m_originSize, m_matrix);
}

// Get a section of a matrix.
template<class T>
Matrix<T> Matrix<T>::section(const int x, const int y, const int width, const int height) const
{
    return Matrix(QPoint(x, y), QSize(width, height), m_originSize, m_matrix);
}

// Constructor
// Creates a matrix as a part of an existing matrix.
template<class T>
Matrix<T>::Matrix(const QPoint &leftTop, const QSize &size, const QSize& origin, T *matrix) :
    m_leftTop(leftTop),
    m_size(size),
    m_originSize(origin),
    m_matrix(matrix),
    m_isSection(true)
{

}

// Protcted
// Copy the left top corner to right bottom.
template<class T>
bool Matrix<T>::copyAxisLeftTopToRightBottom(const CopyArea area)
{
    if (m_size.width() != m_size.height()) {
        return false;
    }
    int startX = 0;
    for (int y=0; y<m_size.height(); ++y) {
        ++startX;
        for (int x=startX; x<m_size.width(); ++x) {
            switch (area) {
            case RightTop: {
                T sourceObj = field(x, y);
                setField(sourceObj, y, x);
                break;
            }
            case LeftBottom: {
                T sourceObj = field(y, x);
                setField(sourceObj, x, y);
                break;
            }
            default:
                return false;
                break;
            }
        }
    }

    return true;
}

// Protected
// Copy right top corner or left bottom corner on diagonal axis.
template<class T>
bool Matrix<T>::copyAxisLeftBottomToRightTop(const Matrix::CopyArea area)
{
    if (m_size.width() != m_size.height()) {
        return false;
    }
    int width = m_size.width();
    for (int y=0; y<m_size.height(); ++y) {
        --width;
        for (int x=0; x<width; ++x) {
            switch (area) {
            case RightTop: {
                T sourceObj = field(x, y);
                int destX = m_size.height() - y + 1;
                int destY = m_size.width() - x + 1;
                setField(sourceObj, destX, destY);
                break;
            }
            case LeftBottom: {
                int sourceX = m_size.height() - y + 1;
                int sourceY = m_size.width() - x + 1;
                T sourceObj = field(sourceX, sourceY);
                setField(sourceObj, sourceX, sourceY);
                break;
            }
            default:
                return false;
                break;
            }
        }
    }

    return true;
}

// Protected
// Copy top area to bottom or bottom to top.
template<class T>
bool Matrix<T>::copyAxisHorizontal(const Matrix::CopyArea area)
{
    if (m_size.height() % 2 == 0) {
        return false;
    }
    for (int y=0; y<m_size.height()/2+1; ++y) {
        for (int x=0; x<m_size.width(); ++x) {
            switch (area) {
            case HorzTop: {
                T sourceObj = field(x, y);
                int destY = m_size.height() - 1 - y;
                setField(sourceObj, x, destY);
                break;
            }
            case HorzBottom: {
                int sourceY = m_size.height() - 1 - y;
                T sourceObj = field(x, sourceY);
                setField(sourceObj, x, y);
                break;
            }
            default:
                return false;
                break;
            }
        }
    }

    return true;
}

// Protected
// Copy left siode to right or wise versa.
template<class T>
bool Matrix<T>::copyAxisVertical(const Matrix::CopyArea area)
{
    if (m_size.width() % 2 == 0) {
        return false;
    }
    for (int y=0; y<m_size.height(); ++y) {
        for (int x=0; x<m_size.width()/2+1; ++x) {
            switch (area) {
            case VertLeft: {
                T sourceObj = field(x, y);
                int destX = m_size.width() - 1 - x;
                setField(sourceObj, destX, y);
                break;
            }
            case VertRight: {
                int sourceX = m_size.width() - 1 - x;
                T sourceObj = field(sourceX, y);
                setField(sourceObj, x, y);
                break;
            }
            default:
                return false;
                break;
            }
        }
    }

    return true;
}

// Initializes the matrix.
// Creates it on the heap and set all fields to null.
template<class T>
void Matrix<T>::initialize(const int width, const int height)
{
    m_matrix = new T[width * height];
}
