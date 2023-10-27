#ifndef __DATA_MANAGER_H__
#define __DATA_MANAGER_H__

#include <tuple>
#include <vector>
#include <cstdint>
#include <string_view>
#include <logic/location.hpp>
#include <logic/players/player.hpp>

namespace Data
{

struct PlayerInfo
{
  Player::Color m_color;
  Player::Type  m_type;
  Location      m_location;
};

std::tuple<uint8_t, std::vector<PlayerInfo>> Import(const std::string _filePath);

}

#endif /* __DATA_MANAGER_H__ */
