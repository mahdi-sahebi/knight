#ifndef __LOGIC_H__
#define __LOGIC_H__

#include <string>
#include "grid.hpp"
#include "data_manager.hpp"

class Logic
{
public:
  Logic(const std::string _filePath);
  Logic() = delete;
  ~Logic();
  void Solve();

private:
  Grid* m_grid;
  std::string m_filePath;
//  Data m_data;
};

#endif /* __LOGIC_H__ */
