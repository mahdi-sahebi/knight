#include <iterator>
#include <algorithm>
#include "data_manager.hpp"
#include <storage/file.hpp>
          #include <iostream>
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
            std::cout << buffer << std::endl;

    string temp = "";
    string::iterator itrBegin = begin(buffer);
    string::iterator itrEnd   = end(buffer);

    const auto isSpace = [](char _char)
    {
      return (' ' == _char);
    };

    const auto isLF = [](char _char)
    {
      return ('\n' == _char);
    };

    /* Extract number of pieces. */
    itrEnd = find_if(itrBegin, itrEnd, isLF);
    temp = string(itrBegin, itrEnd);
    itrBegin = itrEnd + 1;
    const uint8_t playersNumber = atoi(temp.c_str());

    for (uint8_t playerIdx = 0; playerIdx < playersNumber; playerIdx++)
    {
      /* Extract Color */
//      buffer.find()
//      itrBegin = std::find(std::begin(buffer) + itrBegin, )
//      buffer.substr(itr)
    }

    file.close();
  }

  return data;
}

}
