#ifndef __PLAYER_KNIGHT_H__
#define __PLAYER_KNIGHT_H__

#include "player.hpp"

class Knight : public Player
{
public:
  bool canGoTo(const Column _column, const Row _row) override;
private:
};

#endif /* __PLAYER_KNIGHT_H__ */
