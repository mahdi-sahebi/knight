#include "player_manager.hpp"


using namespace PlayerManager;


PlayerInfo::PlayerInfo(Player::Color _color, Player::Type _type, Location _location) :
  m_color(_color), m_type(_type), m_location(_location)
{

}

Player* PlayerManager::Generate(const PlayerInfo& _descriptor)
{
  Player* player = nullptr;

  // TODO(MN): Use open-close principle
  if (Player::Type::PAWN == _descriptor.m_type)
    player = new Knight(_descriptor.m_color);
  else if (Player::Type::BISHOP == _descriptor.m_type)
    player = new Bishop(_descriptor.m_color);
  else if (Player::Type::KNIGHT == _descriptor.m_type)
    player = new Knight(_descriptor.m_color);
  else if (Player::Type::ROOK == _descriptor.m_type)
    player = new Rook(_descriptor.m_color);
  else if (Player::Type::QUEEN == _descriptor.m_type)
    player = new Queen(_descriptor.m_color);
  else if (Player::Type::KING == _descriptor.m_type)
    player = new King(_descriptor.m_color);

  return player;
}
