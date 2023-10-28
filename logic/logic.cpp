#include "logic.hpp"
#include "data_manager.hpp"


using namespace std;
using namespace Data;
using namespace PlayerManager;


Logic::Logic(const string _filePath) :
  m_knight(nullptr)
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
  const vector<PlayerInfo> playerInfoList = std::get<1>(data);


  /* Generate players and arrange. */
  m_knight = nullptr;
  for (const PlayerInfo& playerInfo : playerInfoList)
  {
    Player* player = PlayerManager::Generate(playerInfo);// TODO(MN): Delete players. use unique_ptr

    /* The first player is the Knight */
    if (nullptr == m_knight)
      m_knight = player;

    m_grid->put(player, player->m_location);
  }

  /* Find the best path. */


  /* Export result to the file. */

  int x = 0;
}
