#include "bishop.hpp"

Bishop::Bishop(const Player::Color _color, const Location _location) :
  Player(Player::BISHOP, _color, _location)
{

}

Bishop::~Bishop()
{

}

bool Bishop::canGoTo(const Location _location)
{
  bool isValidMove = false;
  // TODO(MN): Implement
  return isValidMove;
}
