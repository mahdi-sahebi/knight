#ifndef __PLAYER_MANAGER_H__
#define __PLAYER_MANAGER_H__


#include "player.hpp"
#include "pawn.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include <common/location.hpp>


namespace PlayerManager
{

struct PlayerInfo // TODO(MN): Rename to Descriptor
{
  PlayerInfo(Player::Color _color, Player::Type _type, Location _location);
  Player::Color m_color;
  Player::Type  m_type;
  Location      m_location;
};

Player* Generate(const PlayerInfo& _descriptor);

}


#endif /* __PLAYER_MANAGER_H__ */
