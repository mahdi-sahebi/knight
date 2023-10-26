#ifndef __GRID_H__
#define __GRID_H__

#include <cstdbool>
#include <cstdint>
#include "location.hpp"
//#include "player/player.hpp"

class Grid
{
public:
  static Grid* getInstance();
  bool isEmpty(const Column _column, const Row _row);
private:
  Grid();
  ~Grid();
  void clear();

  static Grid* m_instance;
  int m_grids[COL_COUNT][ROW_COUNT]; // TODO(MN): Data type
};

#endif /* __GRID_H__ */
