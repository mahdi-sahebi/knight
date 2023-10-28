#include "pawn.hpp"

Pawn::Pawn(const Player::Color _color, const Location _location) :
  Player(Player::PAWN, _color, _location)
{

}

Pawn::~Pawn()
{

}

bool Pawn::canGoTo(const Column _column, const Row _row)
{
  bool isValidMove = false;

  return isValidMove;
}
