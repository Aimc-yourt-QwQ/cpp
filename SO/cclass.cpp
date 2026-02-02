#include <iostream>
#include <string>
#include <vector>
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
  hello sshello;
  sshello.sayHello();
  return 0;
}
