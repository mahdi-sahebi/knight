#include "rook.hpp"

Rook::Rook(const Player::Color _color, const Location _location) :
  Player(Player::ROOK, _color, _location)
{

}

Rook::~Rook()
{

}

bool Rook::canGoTo(const Column _column, const Row _row)
{
  bool isValidMove = false;

  return isValidMove;
}
