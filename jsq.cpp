#include <iostream>
class calculator
{
  private:
    int A_;
    int B_;
    int C_;
  public:
    void add(int a, int b)
    {
      A_ = a;
      B_ = b;
      C_ = A_ + B_;
      std::cout << C_ << std::endl;
    }
};
int main()
{
  calculator Mycalculator;
  std::cout << "第一个数:";
  std::cin >> a;
  std::cout << "第二个数:";
  std::cin >> b;
  Mycalculator.add(a, b);
  return 0;
}
