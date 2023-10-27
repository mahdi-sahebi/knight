#include "logic.hpp"
#include "data_manager.hpp"


using namespace std;
using namespace Data;

Logic::Logic(const string _filePath)
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
  auto const data = Data::Import(m_filePath);
  const uint8_t movements = std::get<0>(data);
  const vector<PlayerInfo> players = std::get<1>(data);

  int x = 0;
  /* Generate players and arrange. */

  /* Find the best path. */

  /* Export result to the file. */
}
