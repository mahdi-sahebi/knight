#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>

class Player
{
  enum Type
  {
    QUEEN,
    KING,
    SOLDIER,
    HORSE,// TODO(MN): Complete types and arrange as the screo
  };

  enum Color
  {
    Black = 0,
    White
  };

public:
  Player(Player::Type _type, Player::Color _color, uint8_t _score);
  Player() = delete;
  ~Player();

  mutable Type m_type;
  mutable Color m_color;
  mutable uint8_t m_row; // TODO(MN): use row/col data type
  mutable uint8_t m_column;
  mutable uint8_t m_score;
private:
};

#endif /* __PLAYER_H__ */
