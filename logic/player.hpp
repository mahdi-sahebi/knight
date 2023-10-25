#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>
#include <cstdbool>

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
  bool isEnemy(const Player& _player);
  virtual bool canGo(uint8_t _column, uint8_t _row) = 0;
  virtual bool move(uint8_t _column, uint8_t _row) = 0;

  mutable Type m_type;
  mutable Color m_color;
  mutable uint8_t m_row; // TODO(MN): use row/col data type
  mutable uint8_t m_column;
  mutable uint8_t m_score;
private:
};

#endif /* __PLAYER_H__ */
