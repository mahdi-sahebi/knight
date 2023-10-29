#include <iostream>
#include <cstring>
#include <logic/logic.hpp>
                             #include <storage/file.hpp>// TODO(MN): Remove
                      #include <fstream>
int main(int _n, char* _args[])
{
//  std::string filePath(_args[0]);
  // TODO(MN): Output example 1 is wrong in PDF. b6-e6 is imposible.
  // TODO(MN): Output example 3 is wrong in PDF. There is no black player to hit.
  // TODO(MN): Output example 4 is wrong in PDF. Number of players is 4, not 5
  // TODO(MN): Output example 5 is wrong in PDF. Number of players is 4, not 5

  std::string filePath = "/home/mahdi/in.txt";
  Logic logic(filePath);
  logic.Solve();

  return 0;
}

