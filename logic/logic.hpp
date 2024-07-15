#ifndef __LOGIC_H__
#define __LOGIC_H__

#include <string>
#include <stack>
#include "data_manager.hpp"
#include "grid.hpp"

class Logic
{
public:
  Logic(const std::string _inputFilePath, const std::string _outputFilePath);
  Logic() = delete;
  ~Logic();
  void Solve();

private:
  void onPlayerIterate (const Location _location);
  void resetMainPlayer ();
  void chooseMainPlayer(std::shared_ptr<Player> _player);
  void resetAnswer     ();
  bool isAlphabetLess  (std::stack<Location> _path1, std::stack<Location> _path2);
  void arrangePlayers  (const std::vector<PlayerManager::PlayerDescriptor>& _descriptorList);
  void findBestPath();

  Grid m_grid;
  std::string m_inputFilePath;
  std::string m_outputFilePath;
  std::shared_ptr<Player> m_mainPlayer;
  uint8_t m_maxMovesDepth;
  uint8_t m_movesDepth;

  uint8_t m_score;
  uint8_t m_hitCount;
  std::stack<Location> m_path;

  uint8_t m_bestScore;
  uint8_t m_bestHitCount;
  std::stack<Location> m_bestPath;
};

#endif /* __LOGIC_H__ */
