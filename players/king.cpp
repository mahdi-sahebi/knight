#include "king.hpp"

King::King(const Player::Color _color, const Location _location) :
  Player(Player::KING, _color, _location)
{

}

King::~King()
{

}

bool King::canGoTo(const Column _column, const Row _row)
{
  bool isValidMove = false;

  return isValidMove;
}
