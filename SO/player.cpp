#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int hp;

public:
    // 构造函数：玩家出生
    Player(std::string n, int h) {
        name = n;
        hp = h;
        std::cout << "Player " << name << " created with HP = " << hp << std::endl;
    }

    // 行为：受伤
    void takeDamage(int dmg) {
        hp -= dmg;
        if (hp < 0) hp = 0;
        std::cout << name << " takes " << dmg << " damage, HP = " << hp << std::endl;
    }

    // 行为：查看状态
    void showStatus() {
        std::cout << "[Player] " << name << " | HP: " << hp << std::endl;
    }
};

int main() {
    Player p1("Alice", 100);

    p1.showStatus();
    p1.takeDamage(30);
    p1.takeDamage(80);

    return 0;
}
