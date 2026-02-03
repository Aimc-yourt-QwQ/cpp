#include <iostream>
class hello
{
  public:
    void sayHello()
    {
      std::cout << "hello" << std::endl;
    }
};
int main()
{
  hello Obj;
  Obj.sayHello();
  return 0;
}
