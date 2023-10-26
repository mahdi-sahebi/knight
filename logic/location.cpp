#include "location.hpp"


Row& operator++(Row& _row)
{
  _row = static_cast<Row>((static_cast<uint8_t>(_row) + 1));
  return _row;
}

Row& operator--(Row& _row)
{
  _row = static_cast<Row>((static_cast<uint8_t>(_row) - 1));
  return _row;
}

Column& operator++(Column& _col)
{
  _col = static_cast<Column>(static_cast<uint8_t>(_col) + 1);
  return _col;
}

Column& operator--(Column& _col)
{
  _col = static_cast<Column>(static_cast<uint8_t>(_col) - 1);
  return _col;
}


