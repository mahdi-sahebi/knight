#include "queen.hpp"

Queen::Queen(const Player::Color _color, const Location _location) :
  Player(Player::QUEEN, _color, _location)
{

}

Queen::~Queen()
{

}

bool Queen::canGoTo(const Column _column, const Row _row)
{
  bool isValidMove = false;

  return isValidMove;
}
