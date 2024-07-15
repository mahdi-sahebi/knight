#ifndef __PLAYER_MANAGER_H__
#define __PLAYER_MANAGER_H__

#include <common/location.hpp>
#include "player.hpp"
#include "pawn.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include "queen.hpp"
#include "king.hpp"


namespace PlayerManager
{

struct PlayerDescriptor
{
  PlayerDescriptor(Player::Color _color, Player::Type _type, Location _location);
  Player::Color m_color;
  Player::Type  m_type;
  Location      m_location;
};

Player* Generate(const PlayerDescriptor& _descriptor);

}


#endif /* __PLAYER_MANAGER_H__ */
