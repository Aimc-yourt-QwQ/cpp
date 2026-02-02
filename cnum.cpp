#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  int randomNUM = std::rand() % 100 + 1;
  int guess = 0;
  int attempts = 0;

  while (guess != randomNUM) {
    std::cout << "输入你的猜测：";
    std::cin >> guess;
    attempts++;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "return1 \n";
      continue;
    }

    if (guess < randomNUM) {
      std::cout << "太小了 \n";
    } else if (guess > randomNUM) {
      std::cout << "太大了 \n";
    } else {
      std::cout << "总共：" << attempts << "次 \n";
    }
  }
}
