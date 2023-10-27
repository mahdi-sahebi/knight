#include "logic.hpp"
#include "data_manager.hpp"


using namespace std;
using namespace Data;
using namespace PlayerManager;


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


  /* Generate players and arrange. */
  for (const PlayerInfo& player : players)
  {
//    new P
  }

  /* Find the best path. */


  /* Export result to the file. */

  int x = 0;
}
