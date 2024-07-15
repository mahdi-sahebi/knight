#ifndef __PLAYER_ROOK_H__
#define __PLAYER_ROOK_H__

#include "player.hpp"

class Rook : public Player
{
public:
  Rook() = delete;
  Rook(const Player::Color _color, const Location _location);
  ~Rook();
  bool canGoTo(const Location _location) override;
  void iterateFrom(const Location _startLocation, const OnIterate _onIterate) override;
private:
};

#endif /* __PLAYER_ROOK_H__ */
