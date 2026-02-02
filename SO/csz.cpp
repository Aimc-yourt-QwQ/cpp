#include <iostream>
#include <random>
class pulll
{
  public:
    int c;
    void add(int a, int b)
    {
      c = a + b;
      std::cout << c << std::endl;
    }
};
int main()
{
  pulll myObj;
  myObj.add(10, 20);
  return 0;
}
