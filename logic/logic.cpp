#include "logic.hpp"

Logic::Logic(const std::string _filePath)
{
  m_filePath = _filePath;
  m_grid = Grid::getInstance();
}

Logic::~Logic()
{

}

void Logic::Solve()
{
  /* Import data from the file. */
  auto [movements, playerInfoList] = Data::Import(m_filePath);

  /* Generate players and arrange. */

  /* Find the best path. */

  /* Export result to the file. */
}
