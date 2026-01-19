#include <iostream>
#include <string>
class Player {
  protected:
    std::string NAME_;
    int HP_;
  public:
    Player(std::string name, int hp) : NAME_(name), HP_(hp >= 0 ? hp : 1) {
    }
    virtual void GetPlayer() {
      std::cout << "名称：" << NAME_ << "，血量：" << HP_ << std::endl;
    }
    void takeDamage(int DAMAGE_) {
      HP_ -= DAMAGE_;
      if (HP_ <= 0) {
        HP_ = 0;
        std::cout << "角色受到的伤害大于当前血量" << std::endl;
      }
    }
    void healHP(int HEALHP_) {
      if (HP_ <= 0) {
        std::cout << "生命值小于零，跳过治疗" << std::endl;
      } else if (HP_ > 0) {
        HP_ += HEALHP_;
      }
    }
    void setHP(int NEWHP_) {
      HP_ = NEWHP_;
    }
    int getHP() {
      std::cout << HP_ << std::endl;
      return HP_;
    }
};
class Mage : public Player {
  private:
    int MANA_;
  public:
    Mage(std::string name, int hp, int mana) : Player(name, hp), MANA_(mana >= 0 ? mana : 1) {
    }
    void GetPlayer() override {
      std::cout << "名称：" << NAME_ << "，血量：" << HP_ << "，魔力值：" << MANA_ << std::endl;
    }

};
int main() {
  Player p1("Player1", 100);
  Mage p2("mage", 100, 500);
  p1.GetPlayer();
  p2.GetPlayer();
  p1.takeDamage(50);
  p1.takeDamage(70);
  p1.GetPlayer();
  p1.healHP(40);
  p1.GetPlayer();
  p1.getHP();
  return 0;
}
