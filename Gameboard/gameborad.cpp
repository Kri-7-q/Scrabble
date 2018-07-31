#include "gameborad.h"

template<class T>
Gameborad<T>::Gameborad(const int width, const int height) :
    m_width(width),
    m_height(height)
{
    m_board = new T[width * height];
}

// Destructor
// Delete all fields.
template<class T>
Gameborad<T>::~Gameborad()
{
    delete [] m_board;
}

// Set a Field at a given position.
template<class T>
void Gameborad<T>::setField(const T *field, const int x, const int y)
{
    int index = y * m_width + x;
    m_board[index] = field;
}

// Get the field at the given position.
template<class T>
T *Gameborad<T>::fieldAt(const int x, const int y) const
{
    if (x > m_width || y > m_width) {
        return nullptr;
    }
    int index = y * m_width + x;

    return m_board[index];
}

// Mirror the contant within the rect.
// Mirror axis is the diagonal from left-up to right-down.
// All contant left-down corner will be set to right-up corner.
template<class T>
void Gameborad<T>::mirrorDiagonalToRightUp(const QRect &rect)
{
}
