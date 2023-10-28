#ifndef __GRID_H__
#define __GRID_H__

#include <cstdbool>
#include <cstdint>
#include "common/location.hpp"
#include "players/player.hpp"

class Grid
{
public:
  static Grid* getInstance();
  bool isEmpty(const Location _location);// TODO(MN): Use location

private:
  Grid();
  ~Grid();
  void clear();

  static Grid* m_instance;
  Player* m_grids[COL_COUNT][ROW_COUNT];// TODO(MN): Use unique_ptr
};

#endif /* __GRID_H__ */
