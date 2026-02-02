#include <iostream>
class myClass {
  private:
    int i = 10;
    const char* str = "我喜欢你";
  public:
    myClass() {
      std::cout << str << std::endl;
    }

    void IInterface(int newi) {
      std::cout << i << std::endl;
      i = newi;
      std::cout << i << std::endl;
    }
    void getSTR() {
      std::cout << str << std::endl;
    }
};
int main() {
  myClass Obj;
  Obj.IInterface(30);
  Obj.getSTR();
  return 0;
}
