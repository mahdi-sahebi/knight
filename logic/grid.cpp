#include "grid.hpp"


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

bool Grid::isEmpty(const Column _column, const Row _row)
{
  return (0 == m_grids[_column][_row]);
}
