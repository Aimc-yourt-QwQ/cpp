#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
int main()
{
  std::vector<std::string> str = {"h", "e", "l", "l", "o"};
  int i = 0;
  while (i < 5)
  {
    std::cout << str[i] << " ";
    sleep(1);
    i++;
  }
  return 0;
}
