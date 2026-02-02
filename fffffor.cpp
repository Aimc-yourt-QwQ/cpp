#include <iostream>
#include <string>
#include <vector>
int main()
{
  std::vector<std::string> str = {"hello"};
  for (auto it = str.begin(); it != str.end(); ++it)
  {
    std::cout << *it << std::endl;
  }
}
