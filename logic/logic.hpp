#ifndef __LOGIC_H__
#define __LOGIC_H__

#include <string>
#include <stack>
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
  void resetAnswer();

  Grid* m_grid;
  std::string m_filePath;
  Player* m_mainPlayer;
  uint8_t m_maxMovesDepth;
  uint8_t m_movesDepth;

  uint16_t m_score;
  std::stack<Location> m_path;
  uint16_t m_bestScore;
  std::stack<Location> m_bestPath;
};

#endif /* __LOGIC_H__ */
