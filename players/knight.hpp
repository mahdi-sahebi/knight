#ifndef __PLAYER_KNIGHT_H__
#define __PLAYER_KNIGHT_H__

#include "player.hpp"

class Knight : public Player
{
public:
  Knight() = delete;
  Knight(const Player::Color _color, const Location _location);
  ~Knight();
  bool canGoTo(const Location _location) override;
private:
};

#endif /* __PLAYER_KNIGHT_H__ */
