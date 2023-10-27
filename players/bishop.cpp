#include "bishop.hpp"

Bishop::Bishop(const Player::Color _color) : Player(Player::BISHOP, _color)
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
