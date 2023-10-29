#include <cassert>
#include "logic.hpp"
#include "data_manager.hpp"
#include <storage/file.hpp> // TODO(MN): Remove it


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

bool Logic::isAlphabetLess(stack<Location> _path1, stack<Location> _path2)
{
  /* Alphabets are on the column field, not the row, so we need to
   * do the sum on this field within the whole path. */
  uint16_t sumAlpha1 = 0;
  uint16_t sumAlpha2 = 0;

  while (!_path1.empty())
  {
    const auto location1 = _path1.top();
    const auto location2 = _path2.top();

    sumAlpha1 += location1.first;
    sumAlpha2 += location2.first;

    _path1.pop();
    _path2.pop();
  }

  return (sumAlpha2 < sumAlpha1);
}

void Logic::onPlayerIterate(const Location _location)
{
  m_movesDepth++;
  m_path.push(_location);
  assert(m_movesDepth <= m_maxMovesDepth);

  Player*const player = m_grid->get(_location);
  const bool canGo  = (nullptr == player) || m_mainPlayer->isEnemy(*player);
  const bool canHit = (nullptr != player) && m_mainPlayer->isEnemy(*player);
  const Location lastPlayerLocation = m_mainPlayer->m_location;

  if (canHit)
  {
    m_hitCount++;
    m_score += player->m_type;
    m_grid->remove(_location);                /* Pick up enemy. */
    m_grid->remove(m_mainPlayer->m_location); /* Pick up main player. */
    m_mainPlayer->move(_location);            /* Put the main player. */
  }

  if ((m_movesDepth < m_maxMovesDepth) && canGo)
    m_mainPlayer->iterateFrom(_location, std::bind(&Logic::onPlayerIterate, this, std::placeholders::_1));
  else if (m_movesDepth == m_maxMovesDepth)
  {
    if ((m_score > m_bestScore)  ||
        ((m_score == m_bestScore) && (m_hitCount > m_bestHitCount))  ||
        ((m_score == m_bestScore) && (m_hitCount == m_bestHitCount) && isAlphabetLess(m_bestPath, m_path)))
    {
      m_bestScore = m_score;
      m_bestHitCount = m_hitCount;
      // TODO(MN): Copy the path as the best path
      m_bestPath = m_path;
    }
  }

  if (canHit)
  {
    m_hitCount--;
    m_score -= player->m_type;
    m_grid->remove(_location);              /* Pick up the main player. */
    m_mainPlayer->move(lastPlayerLocation); /* Put the main player. */
    m_grid->put(player, _location);         /* Restore the enemy. */
  }

  m_movesDepth--;
  m_path.pop();
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

void Logic::resetAnswer()
{
  m_movesDepth = 0;
  m_score      = 0;
  m_hitCount   = 0;
  while (!m_path.empty())
    m_path.pop();

  m_bestScore    = 0;
  m_bestHitCount = 0;
  while (!m_bestPath.empty())
    m_bestPath.pop();
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
  resetAnswer();
  if (0 != m_maxMovesDepth)
    m_mainPlayer->iterateFrom(m_mainPlayer->m_location, std::bind(&Logic::onPlayerIterate, this, std::placeholders::_1));


  /* Export result to the file. */
  string output = "";
  while (!m_bestPath.empty())
  {
    auto location = m_bestPath.top();
    // TODO(MN): operator
    output = string(1, 'a' + location.first) + string(1, '0' + location.second + 1) + "\n" + output;

    m_bestPath.pop();
  }
  if (0 == m_bestScore)
    output = "!";

  File file;
  file.open("/home/mahdi/out.txt", File::Mode::WRITE);
  file.write(output.c_str(), output.length());
  file.close();

  int x = 0;
}
