#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>
#include <cstdbool>
#include <common/location.hpp>

class Player
{
public:
  enum Type : uint8_t
  {
    PAWN   = 1,
    BISHOP = 2,
    KNIGHT = 3,
    ROOK   = 5,
    QUEEN  = 10,
    KING   = uint8_t(-1),
  };

  enum Color
  {
    Black = 0,
    White
  };

  Player(const Player::Type _type, const Player::Color _color);
  Player() = delete;
  ~Player();
  bool isEnemy(const Player& _player);
  bool canHit(const Player& _player);
  bool move(const Column _column, const Row _row);
  virtual bool canGoTo(const Column _column, const Row _row) = 0;

  mutable Type m_type;
  mutable Color m_color;
  mutable Row m_row;
  mutable Column m_column;
  mutable uint8_t m_score;
private:
};

#endif /* __PLAYER_H__ */
