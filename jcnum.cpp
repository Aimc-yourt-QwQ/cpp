#include <iostream>
#include <random>
using namespace std;
int main(){
  std::uniform_int_distribution<int> d(1,100);
  std::mt19937 rng{std::random_device{}()};
  int n = d(rng), g, c=0;
  for(; std::cin>>g && g!=n; ++c)
    std::cout<<(g<n?"小\n":"大\n");
  std::cout<<c+1;
}
