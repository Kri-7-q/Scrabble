#include "tilebag.h"

TileBag::TileBag()
{
    initilize();
}

// Fill the tile bag with all tiles.
void TileBag::fillBag()
{
    m_contant.clear();
    foreach (QChar letter, m_letterInfoTable.keys()) {
        TileInfo info = m_letterInfoTable.value(letter);
        for (quint8 count=0; count<info.pieceCount(); ++count) {
            m_contant << Tile(letter, info.score());
        }
    }
}

// Initialize the tile info hash table.
void TileBag::initilize()
{
    QString spezial("AÖÜ");
    m_letterInfoTable.insert('A', TileInfo(5, 1));
    m_letterInfoTable.insert('B', TileInfo(2, 3));
    m_letterInfoTable.insert('C', TileInfo(2, 4));
    m_letterInfoTable.insert('D', TileInfo(4, 1));
    m_letterInfoTable.insert('E', TileInfo(15, 1));
    m_letterInfoTable.insert('F', TileInfo(2, 4));
    m_letterInfoTable.insert('G', TileInfo(3, 2));
    m_letterInfoTable.insert('H', TileInfo(4, 2));
    m_letterInfoTable.insert('I', TileInfo(6, 1));
    m_letterInfoTable.insert('J', TileInfo(1, 6));
    m_letterInfoTable.insert('K', TileInfo(2, 4));
    m_letterInfoTable.insert('L', TileInfo(3, 2));
    m_letterInfoTable.insert('M', TileInfo(4, 3));
    m_letterInfoTable.insert('N', TileInfo(9, 1));
    m_letterInfoTable.insert('O', TileInfo(3, 2));
    m_letterInfoTable.insert('P', TileInfo(1, 4));
    m_letterInfoTable.insert('Q', TileInfo(1, 10));
    m_letterInfoTable.insert('R', TileInfo(6, 1));
    m_letterInfoTable.insert('S', TileInfo(7, 1));
    m_letterInfoTable.insert('T', TileInfo(6, 1));
    m_letterInfoTable.insert('U', TileInfo(6, 1));
    m_letterInfoTable.insert('V', TileInfo(1, 8));
    m_letterInfoTable.insert('W', TileInfo(1, 3));
    m_letterInfoTable.insert('X', TileInfo(1, 8));
    m_letterInfoTable.insert('Y', TileInfo(1, 10));
    m_letterInfoTable.insert('Z', TileInfo(1, 3));
    m_letterInfoTable.insert(spezial.at(0), TileInfo(1, 6));
    m_letterInfoTable.insert(spezial.at(1), TileInfo(1, 8));
    m_letterInfoTable.insert(spezial.at(2), TileInfo(1, 6));
    m_letterInfoTable.insert('?', TileInfo(2, 0));
}
