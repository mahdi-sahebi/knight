#ifndef __GRID_H__
#define __GRID_H__

#include <cstdbool>
#include <cstdint>
#include <memory>
#include "common/location.hpp"
#include "players/player.hpp"

class Grid
{
public:
  Grid();
  ~Grid();
  bool                    isEmpty(const Location _location);
  std::shared_ptr<Player> get    (const Location _location);
  void                    remove (const Location _location);
  void                    put    (const std::shared_ptr<Player> _player, const Location _location);

private:
  void clear();
  std::shared_ptr<Player> m_grids[COL_COUNT][ROW_COUNT];
};

#endif /* __GRID_H__ */
