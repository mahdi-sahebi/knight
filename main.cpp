#include <iostream>
#include <cstring>
#include <logic/logic.hpp>

int main(int _n, char* _args[])
{
//  std::string filePath(_args[0]);
  std::string filePath = "/home/mahdi/in.txt";
  std::cout << filePath << std::endl;
  Logic logic(filePath);
  logic.Solve();

  return 0;
}
