#include "queen.hpp"

Queen::Queen(const Player::Color _color, const Location _location) :
  Player(Player::QUEEN, _color, _location)
{

}

Queen::~Queen()
{

}

bool Queen::canGoTo(const Location _location)
{
  bool isValidMove = false;
  // TODO(MN): Implement
  return isValidMove;
}

void Queen::iterateFrom(const Location _startLocation, const OnIterate _onIterate)
{

}
