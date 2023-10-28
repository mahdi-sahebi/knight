#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>
#include <cstdbool>
#include <functional>
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

  typedef std::function<void(const Location)> OnIterate;

  Player(const Player::Type _type, const Player::Color _color, const Location _location);
  Player() = delete;
  ~Player();
  bool isEnemy(const Player& _player);
  bool canHit(const Player& _player);
  bool move(const Location _location);
  virtual bool canGoTo(const Location _location) = 0;
  virtual void iterateFrom(const Location _startLocation, const OnIterate _onIterate) = 0;

  mutable Type m_type;
  mutable Color m_color;
  mutable Row m_row;
  mutable Location m_location;
private:
};

#endif /* __PLAYER_H__ */
