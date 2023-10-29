#include <iostream>
#include <cstring>
#include <logic/logic.hpp>


int main(int _n, char* _args[])
{
  /* The first argument is the program file name. */
  if (3 == _n)
  {
    const std::string inputFilePath(_args[1]);
    const std::string outputFilePath(_args[2]);
    // TODO(MN): Output example 1 is wrong in PDF. b6-e6 is imposible.
    // TODO(MN): Output example 3 is wrong in PDF. There is no black player to hit.
    // TODO(MN): Output example 4 is wrong in PDF. Number of players is 4, not 5
    // TODO(MN): Output example 5 is wrong in PDF. Number of players is 4, not 5

    Logic logic(inputFilePath, outputFilePath);
    logic.Solve();
  }

  return 0;
}
