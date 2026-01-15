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
      std::cout << "创建角色！，嗯......名字是叫" << name << "啊..." << "初始生命是" << hp << "呢ww" << std::endl;
    }
    void takeDamage(int dmg) {
      hp -= dmg;
      if (hp < 0) hp = 0;
      std::cout << "哔哔（机器人音），" << name << "受到了" << dmg << "点伤害！，你还有" << hp << "点生命" << std::endl;
    }
    void showStatus() {
      std::cout << "咳咳，你叫" << name << "。还有" << hp << "点生命值" << std::endl;
    }
};
int main() {
  std::string n;
  int h;

  std::cout << "你叫什么？";
  std::getline(std::cin, n);

  std::cout << "给一个初始生命值";
  std::cin >> h;

  Player p(n, h);
  p.takeDamage(100);
  return 0;
}
