#ifndef FIELD_H
#define FIELD_H

#include <QString>

class Field
{
public:
    Field(const bool isCenter = false);
    Field(const quint8 wordBonus, const quint8 letterBonus);
    Field(const Field& field);

    QString toString() const;

    Field& operator = (const Field& rhs);

private:
    quint8 m_wordBonus;
    quint8 m_letterBonus;
    bool m_isCenter;
};

#endif // FIELD_H
