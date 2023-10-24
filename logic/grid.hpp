#ifndef __GRID_H__
#define __GRID_H__

#include <cstdbool>
#include <cstdint>

//namespace Grid
//{

enum Row : uint8_t
{
  ROW_8 = 0,
  ROW_7,
  ROW_6,
  ROW_5,
  ROW_4,
  ROW_3,
  ROW_2,
  ROW_1,
  ROW_COUNT,
};

Row& operator++(Row& _row);
Row& operator--(Row& _row);


enum Column : uint8_t
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

//}


class Grid
{
public:
  static Grid* getInstance();
  bool isEmpty(Column const _column, Row const _row);
private:
  Grid();
  ~Grid();
  void clear();

  static Grid* m_instance;
  int m_grids[COL_COUNT][ROW_COUNT]; // TODO(MN): Data type
};

#endif /* __GRID_H__ */
