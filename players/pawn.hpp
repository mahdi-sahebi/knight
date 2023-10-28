#ifndef __PLAYER_PAWN_H__
#define __PLAYER_PAWN_H__

#include "player.hpp"

// TODO(MN): Use Player namespace
class Pawn : public Player
{
public:
  Pawn() = delete;
  Pawn(const Player::Color _color, const Location _location);
  ~Pawn();
  bool canGoTo(const Column _column, const Row _row) override;
private:
};

#endif /* __PLAYER_PAWN_H__ */
