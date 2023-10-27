#include "data_manager.hpp"
#include <storage/file.hpp>

using namespace Data;
using namespace std;

std::tuple<uint8_t, vector<PlayerInfo>> Import(const string_view _filePath)
{
  // TODO(MN): Don't return copy of a vector. use singleton to return the reference of a static vector.
  std::tuple<uint8_t, vector<PlayerInfo>> data;

  File file;
//  file.open(_fileP)

  return data;
}
