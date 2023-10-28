#include "king.hpp"

King::King(const Player::Color _color, const Location _location) :
  Player(Player::KING, _color, _location)
{

}

King::~King()
{

}

bool King::canGoTo(const Location _location)
{
  bool isValidMove = false;
  // TODO(MN): Implement
  return isValidMove;
}
