#include "player.hpp"

Player::Player(const Player::Type _type, const Player::Color _color, Location _location) :
  m_type(_type), m_color(_color), m_location(_location)
{

}

Player::~Player()
{

}

bool Player::isEnemy(const Player& _player)
{
  return (m_color != _player.m_color);
}

bool Player::move(const Column _column, const Row _row)
{
  bool const isValidMove = canGoTo(_column, _row);

  if (isValidMove)
    m_location = Location(_column, _row);

  return isValidMove;
}

bool Player::canHit(const Player& _player)
{
  return (isEnemy(_player) && canGoTo(_player.m_location.first, _player.m_location.second));
}
