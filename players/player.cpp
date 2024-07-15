#include "player.hpp"

Player::Player(const Player::Type _type, const Player::Color _color, const Location _location) :
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

bool Player::move(const Location _location)
{
  bool const isValidMove = canGoTo(_location);

  if (isValidMove)
    m_location = _location;

  return isValidMove;
}

bool Player::canHit(const Player& _player)
{
  return (isEnemy(_player) && canGoTo(_player.m_location));
}
