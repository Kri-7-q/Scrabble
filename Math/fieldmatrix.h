#ifndef FIELDMATRIX_H
#define FIELDMATRIX_H

#include "Math/matrix.h"
#include "Gameboard/field.h"

class FieldMatrix : public Matrix<Field>
{
public:
    FieldMatrix() = delete;
    FieldMatrix(const Matrix<Field>& matrix);
    FieldMatrix(const int width, const int height);

    QString toString() const;
};

#endif // FIELDMATRIX_H
