#include <iostream>
#include <string>
class Player {
  private:
    std::string name;
    int MaxHP = 600;
    double MaxMana = 10000.0;
    int hp;
    double mana;
  public:
    Player(std::string n, int h, double m) {
      name = n;
      hp = h;
      mana = m;
      if (hp > MaxHP) hp = MaxHP;
      if (mana > MaxMana) mana = MaxMana;
      std::cout << "角色" << name << "已创建，生命值：" << hp << "，魔力值：" << mana << std::endl;
    }
    void takeDamage(int dmg) {
      hp -= dmg;
      std::cout << name << "受到了" << dmg << "点伤害，剩余生命值：" << hp << std::endl;
    }
    void healhp(int Hamount) {
      hp += Hamount;
      std::cout << name << "回复了" << Hamount << "点生命，剩余生命值：" << hp << std::endl;
    }
    void takeMana(double TMamount) {
      mana -= TMamount;
      std::cout << name << "扣除了" << TMamount << "点魔力，剩余魔力：" << mana << std::endl;
    }
    void healmana(double Mamount) {
      mana += Mamount;
      std::cout << name << "回复了" << Mamount << "点魔力，剩余魔力：" << mana << std::endl;
    }
};
int main() {
  Player p("Alice", 700, 97979.734);
  return 0;
}
