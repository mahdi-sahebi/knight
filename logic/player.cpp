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
