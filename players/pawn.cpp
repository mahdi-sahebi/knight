#include "pawn.hpp"

Pawn::Pawn(const Player::Color _color) : Player(Player::PAWN, _color)
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
