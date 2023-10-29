#include <iterator>
#include <algorithm>
#include <vector>
#include <string_view>
#include <functional>
#include "data_manager.hpp"
#include <storage/file.hpp>

using namespace Data;
using namespace std;
using namespace PlayerManager;

namespace Data
{

static uint8_t extractPlayersNumber(string_view::iterator& _itrBegin,
                                    const string_view::iterator& _itrEnd,
                                    const function<bool(char)>& _comp)
{
  const string_view::iterator itrEnd = find_if(_itrBegin, _itrEnd, _comp);
  const string temp = string(_itrBegin, itrEnd);
  _itrBegin = itrEnd + 1;
  const uint8_t playersNumber = atoi(temp.c_str());
  return playersNumber;
}

static Player::Color extractColor(string_view::iterator& _itrBegin,
                                  const string_view::iterator& _itrEnd,
                                  const function<bool(char)>& _comp)
{
  const string_view::iterator itrEnd = find_if(_itrBegin, _itrEnd, _comp);
  const string temp = string(_itrBegin, itrEnd);
  _itrBegin = itrEnd + 1;
  const Player::Color color = static_cast<Player::Color>(atoi(temp.c_str()));
  return color;
}

static Player::Type extractType(string_view::iterator& _itrBegin,
                                const string_view::iterator& _itrEnd,
                                const function<bool(char)>& _comp)
{
  const string_view::iterator itrEnd = find_if(_itrBegin, _itrEnd, _comp);
  const string temp = string(_itrBegin, itrEnd);
  _itrBegin = itrEnd + 1;
  const Player::Type type = static_cast<Player::Type>(atoi(temp.c_str()));
  return type;
}

static Location extractLocation(string_view::iterator& _itrBegin,
                                             const string_view::iterator& _itrEnd,
                                             const function<bool(char)>& _comp)
{
  const string_view::iterator itrEnd = find_if(_itrBegin, _itrEnd, _comp);
  const string temp = string(_itrBegin, itrEnd);
  _itrBegin = itrEnd + 1;
  const Column column = static_cast<Column>(temp.c_str()[0] - 'a');
  const Row    row    = static_cast<Row>   (atoi(temp.substr(1, 1).c_str()) - 1);
  return Location(column, row);
}

tuple<uint8_t, vector<PlayerDescriptor>> Import(const string _filePath)
{
  tuple<uint8_t, vector<PlayerDescriptor>> data;

  File file;
  if (file.open(_filePath, File::Mode::READ))
  {
    string readBuffer;
    file.read(readBuffer);
    file.close();
    const string_view buffer = readBuffer;

    string temp = "";
    string_view::iterator       itrBegin = begin(buffer);
    const string_view::iterator itrEnd   = end(buffer);

    const auto isSpace = [](char _char)
    {
      return (' ' == _char);
    };

    const auto isLF = [](char _char)
    {
      return ('\n' == _char);
    };

    const uint8_t playersNumber = extractPlayersNumber(itrBegin, itrEnd, isLF);

    /* Extraction of Players */
    vector<PlayerDescriptor> players;
    for (uint8_t playerIdx = 0; playerIdx < playersNumber; playerIdx++)
    {
      const Player::Color color = extractColor(itrBegin, itrEnd, isSpace);

      Player::Type type = extractType(itrBegin, itrEnd, isSpace);
      if (Player::Color::White == color)
        type = Player::Type::KNIGHT;

      const Location location = extractLocation(itrBegin, itrEnd, isLF);

      players.push_back(PlayerDescriptor(color, type, location));
    }

    /* Extraction of Movement */
    temp = string(itrBegin, end(buffer));
    const uint8_t movements = atoi(temp.c_str());

    data = std::make_tuple(movements, players);
  }

  return data;
}

void Export(std::stack<Location> _bestPath, const uint8_t _bestScore, const std::string _filePath)
{
  string output = "";

  if (0 != _bestScore)
  {
    while (!_bestPath.empty())
    {
      auto location = _bestPath.top();
      // TODO(MN): operator
      output = string(1, 'a' + location.first) + string(1, '0' + location.second + 1) + "\n" + output;

      _bestPath.pop();
    }
  }
  else
    output = "!";

  File file;
  file.open(_filePath, File::Mode::WRITE);
  file.write(output.c_str(), output.length());
  file.close();
}

}
