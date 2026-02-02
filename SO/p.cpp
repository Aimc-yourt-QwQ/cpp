#include <iostream>
int main()
{
  int var = 20;
  std::cout << &var << std::endl;
  int *ptr = &var;
  return 0;
}
