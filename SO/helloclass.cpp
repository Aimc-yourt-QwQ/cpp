#include <iostream>
class Hello {
  public:
    Hello() {
      std::cout << "hello class!" << std::endl;
    }
};
int main() {
  Hello myObj;
  return 0;
}
