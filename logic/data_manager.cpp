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

    const string LF = "\n";
    string temp = "";
    int32_t itrBegin = 0;
    int32_t itrEnd   = 0;

    /* Extract number of pieces. */
    itrBegin = buffer.find(LF);
    temp = buffer.substr(itrEnd, itrEnd - itrBegin);
    uint8_t movements = atoi(temp.c_str());
//    buffer.substr(

    file.close();
  }

  return data;
}

}
