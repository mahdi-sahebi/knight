#include "player_manager.hpp"


using namespace PlayerManager;


PlayerInfo::PlayerInfo(Player::Color _color, Player::Type _type, Location _location) :
  m_color(_color), m_type(_type), m_location(_location)
{

}

Player* Generate(const PlayerInfo& _descriptor)
{
  Player* player = nullptr;

  if (Player::Type::PAWN == _descriptor.m_type)
  {

  }
  else if (Player::Type::BISHOP == _descriptor.m_type)
  {

  }
  else if (Player::Type::KNIGHT == _descriptor.m_type)
  {
//    player = new
  }
  else if (Player::Type::ROOK == _descriptor.m_type)
  {

  }
  else if (Player::Type::QUEEN == _descriptor.m_type)
  {

  }
  else if (Player::Type::KING == _descriptor.m_type)
  {

  }

  return player;
}
