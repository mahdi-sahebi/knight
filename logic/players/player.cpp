#include "player.hpp"

Player::Player(Player::Type _type, Player::Color _color, uint8_t _score) :
  m_type(_type), m_color(_color), m_score(_score)
{

}

Player::~Player()
{

}

bool Player::isEnemy(const Player& _player)
{
  return (m_color != _player.m_color);
}

bool Player::move(uint8_t _column, uint8_t _row)
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
