#include <iterator>
#include <algorithm>
#include "data_manager.hpp"
#include <storage/file.hpp>
          #include <iostream>
using namespace Data;
using namespace std;

namespace Data
{

tuple<uint8_t, vector<PlayerInfo>> Import(const string _filePath)
{
  // TODO(MN): Don't return copy of a vector. use singleton to return the reference of a static vector.
  tuple<uint8_t, vector<PlayerInfo>> data;

  File file;
  if (file.open(_filePath))
  {
    string buffer;
    file.read(buffer);
            std::cout << buffer << std::endl;

    string temp = "";
    string::iterator itrBegin = begin(buffer);
    string::iterator itrEnd   = itrBegin;

    const auto isSpace = [](char _char)
    {
      return (' ' == _char);
    };

    const auto isLF = [](char _char)
    {
      return ('\n' == _char);
    };

    /* Extract number of pieces. */
    itrEnd = find_if(itrBegin, end(buffer), isLF);
    temp = string(itrBegin, itrEnd);
    itrBegin = itrEnd + 1;
    const uint8_t playersNumber = atoi(temp.c_str());

    /* Extraction of Players */
    for (uint8_t playerIdx = 0; playerIdx < playersNumber; playerIdx++)
    {
      /* Color */
      itrEnd = find_if(itrBegin, end(buffer), isSpace);
      temp = string(itrBegin, itrEnd);
      itrBegin = itrEnd + 1;
      const Player::Color color = static_cast<Player::Color>(atoi(temp.c_str()));

      /* Type */
      itrEnd = find_if(itrBegin, end(buffer), isSpace);
      temp = string(itrBegin, itrEnd);
      itrBegin = itrEnd + 1;
      Player::Type type = static_cast<Player::Type>(atoi(temp.c_str()));
      if (Player::Color::White == color)
        type = Player::Type::KNIGHT;

      /* Location */
      itrEnd = find_if(itrBegin, end(buffer), isLF);
      temp = string(itrBegin, itrEnd);
      itrBegin = itrEnd + 1;
      const Column column = static_cast<Column>(temp.c_str()[0] - 'a');
      const Row    row    = static_cast<Row>   (atoi(temp.substr(1, 1).c_str()) - 1);
    }

    /* Extraction of Movement */
    temp = string(itrBegin, end(buffer));
    const uint8_t movements = atoi(temp.c_str());

    file.close();
  }

  return data;
}

}
