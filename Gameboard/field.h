#ifndef FIELD_H
#define FIELD_H

#include <QString>

class Field
{
public:
    enum Feature { None, Word, Letter, Center };

    Field();
    Field(const Feature feature, const quint8 bonus = 0);
    Field(const Field& field);

    QString toString() const;

    Field& operator = (const Field& rhs);

private:
    Feature m_feature;
    quint8 m_bonus;
};

#endif // FIELD_H
