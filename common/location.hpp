#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <cstdint>
#include <utility>

enum Row : int8_t
{
  ROW_1 = 0,
  ROW_2,
  ROW_3,
  ROW_4,
  ROW_5,
  ROW_6,
  ROW_7,
  ROW_8,
  ROW_COUNT,
};

Row& operator++(Row& _row);
Row& operator--(Row& _row);
Row operator+(Row& _rowA, Row& _rowB);
Row& operator+=(Row& _rowA, Row& _rowB);


enum Column : int8_t
{
  COL_A = 0,
  COL_B,
  COL_C,
  COL_D,
  COL_E,
  COL_F,
  COL_G,
  COL_H,
  COL_COUNT,
};

Column& operator++(Column& _col);
Column& operator--(Column& _col);
Column operator+(Column& _colA, Column& _colB);
Column& operator+=(Column& _colA, Column& _colB);

typedef std::pair<int8_t, int8_t> Location;

Location operator+(Location& _a, Location& _b);

#endif /* __LOCATION_H__ */
