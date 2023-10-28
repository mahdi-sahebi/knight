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

Row operator+(Row& _rowA, Row& _rowB)
{
  Row row = static_cast<Row>(static_cast<uint8_t>(_rowA) + static_cast<uint8_t>(_rowB));
  return row;
}

Row& operator+=(Row& _rowA, Row& _rowB)
{
  _rowA = static_cast<Row>(static_cast<uint8_t>(_rowA) + static_cast<uint8_t>(_rowB));
  return _rowA;
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

Column operator+(Column& _colA, Column& _colB)
{
  Column column = static_cast<Column>(static_cast<uint8_t>(_colA) + static_cast<uint8_t>(_colB));
  return column;
}

Column& operator+=(Column& _colA, Column& _colB)
{
  _colA = static_cast<Column>(static_cast<uint8_t>(_colA) + static_cast<uint8_t>(_colB));
  return _colA;
}

Location operator+(Location& _a, Location& _b)
{
  Location c(_a);
  c.first += _b.first;
  c.second += _b.second;
  return c;
}

bool isLocationValid(const Location& _location)
{
  return ((_location.first  >= 0) && (_location.first  < COL_COUNT) &&
          (_location.second >= 0) && (_location.second < ROW_COUNT));
}
