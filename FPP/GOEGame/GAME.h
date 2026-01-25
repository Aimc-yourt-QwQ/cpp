#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <random> // 备用
#include <vector> // 备用
class PlayerTemplate {
  protected:
    std::string NAME_;
    int HP_;
  public:
    PlayerTemplate(std::string name, int hp) : NAME_(name), HP_(hp >= 0 ? hp : 1) {
    }
    virtual void getPlayer() {
      std::cout << NAME_ << " " << HP_ << std::endl;
    }
    void healHP(int HEALHP_) {
      if (HEALHP_ < 0) HEALHP_ = 0;
      HP_ += HEALHP_;
    }
    void takeDamage(int DAMAGE_) {
      HP_ -= DAMAGE_;
    }
    void setHP(int NEWHP_) {
      if (NEWHP_ <= 0) NEWHP_ = 1;
      HP_ = NEWHP_;
    }
};
class Mage : public PlayerTemplate {
  private:
    int MANA_;
  public:
    Mage(std::string name, int hp, int mana) : PlayerTemplate(name, hp), MANA_
(mana >= 0 ? mana : 1) {
    }
    void getPlayer() override {
      std::cout << NAME_ << " " << HP_ << " " << MANA_ << std::endl;
    }
};
class robber : public PlayerTemplate {
  private:
   int agile = 0;
  public:
   robber(std::string name,int hp, int agile) 
}
#endif
