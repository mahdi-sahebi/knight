#include <iostream>
#include <logic/logic.hpp>

int main(int _n, char* _args[])
{
  std::string filePath(_args[0]);
  Logic logic(filePath);
  logic.Solve();

  return 0;
}
