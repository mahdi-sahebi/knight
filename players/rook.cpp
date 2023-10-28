#include "rook.hpp"

Rook::Rook(const Player::Color _color, const Location _location) :
  Player(Player::ROOK, _color, _location)
{

}

Rook::~Rook()
{

}

bool Rook::canGoTo(const Location _location)
{
  bool isValidMove = false;
  // TODO(MN): Implement
  return isValidMove;
}
