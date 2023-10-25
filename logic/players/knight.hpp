#ifndef __PLAYER_KNIGHT_H__
#define __PLAYER_KNIGHT_H__

#include "player.hpp"

class Knight : public Player
{
public:
  bool canGoTo(const uint8_t _column, const uint8_t _row) override;
private:
};

#endif /* __PLAYER_KNIGHT_H__ */
