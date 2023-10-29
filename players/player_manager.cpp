#include <functional>
#include <map>
#include "player_manager.hpp"


using namespace PlayerManager;


PlayerDescriptor::PlayerDescriptor(Player::Color _color, Player::Type _type, Location _location) :
  m_color(_color), m_type(_type), m_location(_location)
{

}

static Player* Generate_Pawn(const PlayerDescriptor& _descriptor)
{
  return new Pawn(_descriptor.m_color, _descriptor.m_location);
}

static Player* Generate_Bishop(const PlayerDescriptor& _descriptor)
{
  return new Bishop(_descriptor.m_color, _descriptor.m_location);
}

static Player* Generate_Knight(const PlayerDescriptor& _descriptor)
{
  return new Knight(_descriptor.m_color, _descriptor.m_location);
}

static Player* Generate_Rook(const PlayerDescriptor& _descriptor)
{
  return new Rook(_descriptor.m_color, _descriptor.m_location);
}

static Player* Generate_Queen(const PlayerDescriptor& _descriptor)
{
  return new Queen(_descriptor.m_color, _descriptor.m_location);
}

static Player* Generate_King(const PlayerDescriptor& _descriptor)
{
  return new King(_descriptor.m_color, _descriptor.m_location);
}

Player* PlayerManager::Generate(const PlayerDescriptor& _descriptor)
{
  Player* player = nullptr;

  std::map<Player::Type, std::function<Player*(const PlayerDescriptor&)>> generators =
  {
    std::make_pair(Player::Type::PAWN,   Generate_Pawn),
    std::make_pair(Player::Type::BISHOP, Generate_Bishop),
    std::make_pair(Player::Type::KNIGHT, Generate_Knight),
    std::make_pair(Player::Type::ROOK,   Generate_Rook),
    std::make_pair(Player::Type::QUEEN,  Generate_Queen),
    std::make_pair(Player::Type::KING,   Generate_King),
  };

  player = generators[_descriptor.m_type](_descriptor);

  return player;
}
