#include <iostream>
#include <string>
class Player {
  private:
    std::string name;
    int hp;
  public:
    Player(std::string n, int h) {
      name = n;
      hp = h;
    }
    void getDMG(int dmg) {
      hp -= dmg;
      if (hp < 0) hp = 0;
    }
    void 
}
