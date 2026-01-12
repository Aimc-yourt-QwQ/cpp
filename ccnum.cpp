#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  int a = std::rand() % 100 + 1;
  int b = 0;
  int c = 0;

  while (b != a) {
    std::cout << "请输入文本";
    std::cin >> b;
    c++;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "return1" << std::endl;
      continue;
    }

    if (b < a) {
      std::cout << "nzjshebjsjzbennekssjbebdbdkkdks \n";
    } else if (b > a) {
      std::cout << "jxbxbxbxbbxbxbx \n";
    } else {
      std::cout << c << endl;
    }
  }
}
