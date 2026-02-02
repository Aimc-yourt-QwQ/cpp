#include <iostream>
using namespace std;
int main(){
  int a;
  int b;
  int c;

  std::cin >> a;
  std::cin >> b;
  c = a + b;
  std::cout << c << std::endl;
  if (c >= 50) {
    return 0;
  } else {
    return 1;
  }
}
