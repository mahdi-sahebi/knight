#include "grid.hpp"


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
      m_grids[col][row] = nullptr;
}

bool Grid::isEmpty(const Location _location)
{
  return (nullptr == m_grids[_location.first][_location.second]);
}

std::shared_ptr<Player> Grid::get(const Location _location)
{
  return m_grids[_location.first][_location.second];
}

void Grid::put(const std::shared_ptr<Player> _player, const Location _location)
{
  m_grids[_location.first][_location.second] = _player;
}

void Grid::remove(const Location _location)
{
  m_grids[_location.first][_location.second] = nullptr;
}
