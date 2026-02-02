#include <iostream>
class hello
{
  public:
    void sayHello()
    {
      std::cout << "hello";
    }
};
int main()
{
  hello myObj;
  myObj.sayHello();
  return 0;
}
