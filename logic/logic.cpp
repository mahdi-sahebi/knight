#include "logic.hpp"
#include "data_manager.hpp"


using namespace std;
using namespace Data;
using namespace PlayerManager;


Logic::Logic(const string _filePath) :
  m_mainPlayer(nullptr)
{
  m_filePath = _filePath;
  m_grid = Grid::getInstance();
}

Logic::~Logic()
{

}

void Logic::onPlayerIterate(const Location _location)
{
  m_movesDepth++;

  if (m_movesDepth < m_maxMovesDepth)
  {
    m_mainPlayer->iterateFrom(m_mainPlayer->m_location, std::bind(&Logic::onPlayerIterate, this, std::placeholders::_1));
  }
  else
  {

  }


  m_movesDepth--;
}

void Logic::resetMainPlayer()
{
  m_mainPlayer = nullptr;
}

void Logic::chooseMainPlayer(Player* _player)
{
  /* The first player is the Knight */
  if (nullptr == m_mainPlayer)
    m_mainPlayer = _player;
}

void Logic::Solve()
{
  /* Import data from the file. */
  auto const data = Data::Import(m_filePath);
  m_maxMovesDepth = std::get<0>(data);
  const vector<PlayerInfo> playerInfoList = std::get<1>(data);


  /* Generate players and arrange. */
  resetMainPlayer();

  for (const PlayerInfo& playerInfo : playerInfoList)
  {
    Player* player = PlayerManager::Generate(playerInfo);// TODO(MN): Delete players. use unique_ptr
    chooseMainPlayer(player);
    m_grid->put(player, player->m_location);
  }


  /* Find the best path. */
  m_movesDepth = 0;
  m_mainPlayer->iterateFrom(m_mainPlayer->m_location, std::bind(&Logic::onPlayerIterate, this, std::placeholders::_1));


  /* Export result to the file. */

  int x = 0;
}
