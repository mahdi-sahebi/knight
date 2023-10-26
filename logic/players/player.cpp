#include "player.hpp"

Player::Player(const Player::Type _type, const Player::Color _color) :
  m_type(_type), m_color(_color), m_score(_type)
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
  {
    m_column = _column;
    m_row    = _row;
  }

  return isValidMove;
}

bool Player::canHit(const Player& _player)
{
  return (isEnemy(_player) && canGoTo(_player.m_column, _player.m_row));
}
