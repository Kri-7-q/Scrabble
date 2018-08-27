#include "fieldmatrix.h"

// Constructor
// Constructs a matrix of Field objects from another matrix.
FieldMatrix::FieldMatrix(const Matrix<Field> &matrix) :
    Matrix<Field>(matrix)
{

}

// Constructor
// Constructs a matrix of Field objects with given size.
FieldMatrix::FieldMatrix(const int width, const int height) :
    Matrix<Field>(width, height)
{

}

// Get a string reprasentation of the matrix.
QString FieldMatrix::toString() const
{
    QString matrix;
    for (int y=0; y<width(); ++y) {
        for (int x=0; x<height(); ++x) {
            Field f = field(x, y);
            matrix.append(f.toString()).append(' ');
        }
        matrix.append('\n');
    }

    return matrix;
}
