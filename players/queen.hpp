#ifndef __PLAYER_QUEEN_H__
#define __PLAYER_QUEEN_H__

#include "player.hpp"

class Queen : public Player
{
public:
  Queen() = delete;
  Queen(const Player::Color _color, const Location _location);
  ~Queen();
  bool canGoTo(const Location _location) override;
  void iterateFrom(const Location _startLocation, const OnIterate _onIterate) override;
private:
};

#endif /* __PLAYER_QUEEN_H__ */
