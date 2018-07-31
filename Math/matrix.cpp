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
    m_matrix = new T[width * height];
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
    m_matrix = new T[size.width() * size.height()];
}

// Set a field at a given position in the matrix.
template<class T>
void Matrix<T>::setField(const T *field, const int x, const int y)
{
    int index = m_originSize.width() * (y + m_leftTop.y()) + x + m_leftTop.x();
    m_matrix[index] = field;
}

// Get the field at a given position from the matrix.
template<class T>
T *Matrix<T>::field(const int x, const int y) const
{
    int index = m_originSize.width() * (y + m_leftTop.y()) + x + m_leftTop.x();

    return m_matrix[index];
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
