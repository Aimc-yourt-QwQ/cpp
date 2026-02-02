#include <iostream>
class base
{
  public:
   virtual void hello()
    {
      std::cout << "hello" << std::endl;
    }
};
class fuck : public base
{
  public:
    void hello() override
    {
      std::cout << "fuck you" << std::endl;
    }
};
int main()
{
  base myBase;
  myBase.hello();
  fuck myFuck;
  myFuck.hello();
  return 0;
}
