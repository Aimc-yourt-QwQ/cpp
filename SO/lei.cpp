#include <iostream>
#include <string>
class Hello{
private:
  std::string m;

public:
  Hello(){
    m = "Hello World";
  }
  void display(){
    std::cout << m << '\n';
  }
};
int main(){
  Hello myObj;
  myObj.display();
  return 0;
}
