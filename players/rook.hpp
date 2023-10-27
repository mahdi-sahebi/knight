#ifndef __PLAYER_ROOK_H__
#define __PLAYER_ROOK_H__

#include "player.hpp"

class Rook : public Player
{
public:
  Rook() = delete;
  Rook(const Player::Color _color);
  ~Rook();
  bool canGoTo(const Column _column, const Row _row) override;
private:
};

#endif /* __PLAYER_ROOK_H__ */
