
#include <iostream>
#include <string>
#include <limits>

class Player {
private:
    std::string name;
    int hp;

public:
    Player(std::string n, int h) {
        name = n;
        hp = h;
        std::cout << "Player " << name << " created with HP = " << hp << std::endl;
    }

    void takeDamage(int dmg) {
        hp -= dmg;
        if (hp < 0) hp = 0;
        std::cout << name << " takes " << dmg << " damage, HP = " << hp << std::endl;
    }
    void heal(int amount) {
      hp += amount;
      std::cout << name << " takes " << amount << " heal, HP = " << hp << std::endl;
    }

    void showStatus() {
        std::cout << "[Player] " << name << " | HP: " << hp << std::endl;
    }
};

int main() {
  std::string n;
  int h;
  std::cout << "角色名：";
  std::getline(std::cin, n);

  std::cout << "初始生命：";
  std::cin >> h;

  Player p(n, h);
  p.showStatus();
  p.takeDamage(30);
  p.heal(10);

  return 0;
}
