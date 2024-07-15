#include <cmath>
#include "knight.hpp"

Knight::Knight(const Player::Color _color, const Location _location) :
  Player(Player::KNIGHT, _color, _location)
{

}

Knight::~Knight()
{

}

bool Knight::canGoTo(const Location _location)
{
  bool isValidMove = false;

  if (isLocationValid(_location))
  {
    constexpr bool mask[5][5] =
    {
      {0,1,0,1,0},
      {1,0,0,0,1},
      {0,0,0,0,0},
      {1,0,0,0,1},
      {0,1,0,1,0},
    };

    constexpr uint8_t offsetY = 2;
    constexpr uint8_t offsetX = 2;

    Location location = _location;
    const Location dif = m_location - location;

    if ((abs(dif.first) <= 2) && (abs(dif.second) <= 2))
      isValidMove = mask[dif.first + offsetX][dif.second + offsetY];
  }

  return isValidMove;
}

void Knight::iterateFrom(const Location _startLocation, const OnIterate _onIterate)
{
  Location offsets[] =
  {
    {-2, -1},
    {-2, +1},
    {-1, -2},
    {-1, +2},
    {+1, -2},
    {+1, +2},
    {+2, -1},
    {+2, +1},
  };

  Location startLocation = _startLocation;

  for (auto& offset : offsets)
  {
    const Location location = (startLocation + offset);
    if (!isLocationValid(location))
      continue;

    _onIterate(location);
  }
}
