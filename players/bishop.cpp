#include "bishop.hpp"

Bishop::Bishop(const Player::Color _color, const Location _location) :
  Player(Player::BISHOP, _color, _location)
{

}

Bishop::~Bishop()
{

}

bool Bishop::canGoTo(const Column _column, const Row _row)
{
  bool isValidMove = false;

  return isValidMove;
}
