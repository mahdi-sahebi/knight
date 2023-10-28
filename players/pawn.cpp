#include "pawn.hpp"

Pawn::Pawn(const Player::Color _color, const Location _location) :
  Player(Player::PAWN, _color, _location)
{

}

Pawn::~Pawn()
{

}

bool Pawn::canGoTo(const Location _location)
{
  bool isValidMove = false;
  // TODO(MN): Implement
  return isValidMove;
}

void Pawn::iterateFrom(const Location _startLocation, const OnIterate _onIterate)
{

}
