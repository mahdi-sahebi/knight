#ifndef __PLAYER_KING_H__
#define __PLAYER_KING_H__

#include "player.hpp"

class King : public Player
{
public:
  King() = delete;
  King(const Player::Color _color, const Location _location);
  ~King();
  bool canGoTo(const Location _location) override;
private:
};

#endif /* __PLAYER_KING_H__ */
