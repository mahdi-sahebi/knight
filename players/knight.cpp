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
  const uint8_t column = _location.first;
  const uint8_t row    = _location.second;

  if ((column < COL_COUNT) && (row < ROW_COUNT))
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

    const int8_t difColumn = m_location.first - column;
    const int8_t difRow = m_location.second - row;

    if ((abs(difColumn) <= 2) && (abs(difRow) <= 2))
      isValidMove = mask[difColumn + offsetX][difRow + offsetY];
  }

  return isValidMove;
}

void Knight::iterateFrom(const Location _startLocation, const OnIterate _onIterate)
{

}
