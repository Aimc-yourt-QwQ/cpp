#include <iostream>
#include <string>
class MyClass {
  public:
    MyClass() {
      for (int i = 0; i <= 10; i++) {
        std::cout << i << std::endl;
      }
    }
};
int main(){
  MyClass myObj;
  return 0;
}
