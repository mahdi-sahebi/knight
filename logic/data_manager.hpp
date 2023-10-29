#ifndef __DATA_MANAGER_H__
#define __DATA_MANAGER_H__

#include <tuple>
#include <vector>
#include <cstdint>
#include <string>
#include <players/player_manager.hpp>
#include <stack>

namespace Data
{
std::tuple<uint8_t, std::vector<PlayerManager::PlayerDescriptor>> Import(const std::string _filePath);
void Export(std::stack<Location> _bestPath, const uint8_t _bestScore, const std::string _filePath);
}

#endif /* __DATA_MANAGER_H__ */
