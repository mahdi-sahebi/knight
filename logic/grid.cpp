#include "grid.hpp"


Row& operator++(Row& _row)
{
  _row = static_cast<Row>((static_cast<uint8_t>(_row) + 1));
  return _row;
}

Row& operator--(Row& _row)
{
  _row = static_cast<Row>((static_cast<uint8_t>(_row) - 1));
  return _row;
}

Column& operator++(Column& _col)
{
  _col = static_cast<Column>(static_cast<uint8_t>(_col) + 1);
  return _col;
}

Column& operator--(Column& _col)
{
  _col = static_cast<Column>(static_cast<uint8_t>(_col) - 1);
  return _col;
}


Grid* Grid::m_instance = nullptr;

Grid* Grid::getInstance()
{
  if (nullptr == m_instance)
    m_instance = new Grid();
  return m_instance;
}

Grid::Grid()
{
  clear();
}

Grid::~Grid()
{

}

void Grid::clear()
{
  for (Column col = COL_A; col < COL_COUNT; ++col)
    for (Row row = ROW_8; row < ROW_COUNT; ++row)
      m_grids[col][row] = 0;// TODO(MN): Default value
}

bool Grid::isEmpty(Column const _column, Row const _row)
{
  return (0 == m_grids[_column][_row]);
}
