#ifndef __DATA_MANAGER_H__
#define __DATA_MANAGER_H__

#include <tuple>
#include <vector>
#include <cstdint>
#include <string>
#include <logic/players/player_manager.hpp>

namespace Data
{

std::tuple<uint8_t, std::vector<PlayerManager::PlayerInfo>> Import(const std::string _filePath);

}

#endif /* __DATA_MANAGER_H__ */
