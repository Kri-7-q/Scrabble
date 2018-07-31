#ifndef FIELD_H
#define FIELD_H


class Field
{
public:
    Field();
    Field(const unsigned char wordBonus, const unsigned char letterBonus);

private:
    unsigned char m_wordBonus;
    unsigned char m_letterBonus;
};

#endif // FIELD_H
