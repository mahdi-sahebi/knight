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
  Grid* m_grid;
  std::string m_filePath;
  Player* m_knight;
};

#endif /* __LOGIC_H__ */
