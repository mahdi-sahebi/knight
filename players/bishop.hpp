#ifndef __PLAYER_BISHOP_H__
#define __PLAYER_BISHOP_H__

#include "player.hpp"

class Bishop : public Player
{
public:
  Bishop() = delete;
  Bishop(const Player::Color _color, const Location _location);
  ~Bishop();
  bool canGoTo(const Location _location) override;
  void iterateFrom(const Location _startLocation, const OnIterate _onIterate) override;
private:
};

#endif /* __PLAYER_BISHOP_H__ */
