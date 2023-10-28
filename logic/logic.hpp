#ifndef __LOGIC_H__
#define __LOGIC_H__

#include <string>
#include "grid.hpp"

class Logic
{
public:
  Logic(const std::string _filePath);
  Logic() = delete;
  ~Logic();
  void Solve();

private:
  void onPlayerIterate(const Location _location);
  void resetMainPlayer();
  void chooseMainPlayer(Player* _player);

  Grid* m_grid;
  std::string m_filePath;
  Player* m_mainPlayer;
  uint8_t m_maxMovesDepth;
  uint8_t m_movesDepth;

  uint16_t m_totalScore;
  uint16_t m_bestScore;
};

#endif /* __LOGIC_H__ */
