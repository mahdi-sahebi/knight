#ifndef __PLAYER_QUEEN_H__
#define __PLAYER_QUEEN_H__

#include "player.hpp"

class Queen : public Player
{
public:
  Queen() = delete;
  Queen(const Player::Color _color);
  ~Queen();
  bool canGoTo(const Column _column, const Row _row) override;
private:
};

#endif /* __PLAYER_QUEEN_H__ */
