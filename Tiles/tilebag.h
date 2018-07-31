#ifndef TILEBAG_H
#define TILEBAG_H

#include <QHash>
#include "Tiles/tile.h"
#include "Tiles/tileinfo.h"

class TileBag
{
public:
    TileBag();

    void fillBag();

protected:
    void initilize();

private:
    QHash<QChar, TileInfo> m_letterInfoTable;
    QList<Tile> m_contant;
};

#endif // TILEBAG_H
