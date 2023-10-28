#include <iostream>
#include <cstring>
#include <logic/logic.hpp>

int main(int _n, char* _args[])
{
//  std::string filePath(_args[0]);
  // TODO(MN): Output example is wrong in PDF. b6-e6 is imposible.
  std::string filePath = "/home/mahdi/in.txt";
  Logic logic(filePath);
  logic.Solve();

  return 0;
}
