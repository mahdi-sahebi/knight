#include "data_manager.hpp"
#include <storage/file.hpp>

using namespace Data;
using namespace std;

namespace Data
{

std::tuple<uint8_t, vector<PlayerInfo>> Import(const string _filePath)
{
  // TODO(MN): Don't return copy of a vector. use singleton to return the reference of a static vector.
  std::tuple<uint8_t, vector<PlayerInfo>> data;

  File file;
  if (file.open(_filePath))
  {
    string buffer;
    file.read(buffer);

    const string LF = "\n";
    string temp = "";
    uint16_t itrBegin = 0;
    uint16_t itrEnd   = 0;

    /* Extract number of pieces. */
    itrBegin = buffer.find(LF);
    temp = buffer.substr(itrBegin, itrEnd - itrBegin);

//    buffer.substr(

    file.close();
  }

  return data;
}

}
