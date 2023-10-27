#ifndef __PLAYER_KING_H__
#define __PLAYER_KING_H__

#include "player.hpp"

class King : public Player
{
public:
  King() = delete;
  King(const Player::Color _color);
  ~King();
  bool canGoTo(const Column _column, const Row _row) override;
private:
};

#endif /* __PLAYER_KING_H__ */
