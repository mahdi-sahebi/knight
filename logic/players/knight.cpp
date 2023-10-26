#include <cmath>
#include "knight.hpp"

bool Knight::canGoTo(const Column _column, const Row _row)
{
  bool isValidMove = false;

  if ((_column < COL_COUNT) && (_row < ROW_COUNT))
  {
    constexpr bool mask[5][5] =
    {
      {0,1,0,1,0},
      {1,0,0,0,1},
      {0,0,0,0,0},
      {1,0,0,0,1},
      {0,1,0,1,0},
    };

    constexpr uint8_t offsetY = 2;
    constexpr uint8_t offsetX = 2;

    const int8_t difColumn = m_column - _column;
    const int8_t difRow = m_row - _row;

    if ((abs(difColumn) <= 2) && (abs(difRow) <= 2))
      isValidMove = mask[difColumn + offsetX][difRow + offsetY];
  }

//      uint8_t row = _row;uint8_t column = _column;

//  for (int8_t xItr = -2; xItr <= 2; xItr++)
//  {
//    const int8_t x = column + xItr + offsetX;
//    if ((x < 0) || (x >= COL_COUNT))
//      continue;

//    for (int8_t yItr = -2; yItr <= 2; yItr++)
//    {
//      const int8_t y = row + yItr + offsetY;
//      if ((y < 0) || (y >= ROW_COUNT))
//        continue;

//      /* Hasn't been allowed. */
//      if (0 == mask[xItr + offsetX][yItr + offsetY])
//        continue;

//    }
//  }

  return isValidMove;
}
