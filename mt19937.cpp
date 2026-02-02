#include <iostream>
#include <random>
int main(){
  std::random_device rd{};
  std::mt19937 rng{ rd() };
  std::uniform_int_distribution<int> dist{ 1, 100 };
  
  for (int i = 0; i < 10; i++) {
    std::cout << dist(rng) << '\n';
  }
}
