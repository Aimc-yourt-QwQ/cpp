#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

class Player {
private:
    std::string name_;
    int maxHp_ = 600;
    double maxMana_ = 10000.0;

    int currentHp_;
    double currentMana_;

public:
    Player(const std::string& name, int hp, double mana)
        : name_(name), currentHp_(hp), currentMana_(mana)
    {
        if (currentHp_ > maxHp_) currentHp_ = maxHp_;
        if (currentMana_ > maxMana_) currentMana_ = maxMana_;

        std::cout << "角色 " << name_
                  << " 已创建，生命值：" << currentHp_
                  << "，魔力值：" << currentMana_ << std::endl;
    }

    // 受到伤害
    void takeDamage(int damage) {
        currentHp_ -= damage;
        if (currentHp_ < 0) currentHp_ = 0;

        std::cout << name_ << " 受到了 "
                  << damage << " 点伤害，剩余生命值："
                  << currentHp_ << std::endl;
    }

    // 回复生命值
    void healHp(int amount) {
        currentHp_ += amount;
        if (currentHp_ > maxHp_) currentHp_ = maxHp_;

        std::cout << name_ << " 回复了 "
                  << amount << " 点生命，剩余生命值："
                  << currentHp_ << std::endl;
    }

    // 消耗魔力
    void consumeMana(double amount) {
        currentMana_ -= amount;
        if (currentMana_ < 0) currentMana_ = 0;

        std::cout << name_ << " 消耗了 "
                  << amount << " 点魔力，剩余魔力："
                  << currentMana_ << std::endl;
    }

    // 回复魔力
    void restoreMana(double amount) {
        currentMana_ += amount;
        if (currentMana_ > maxMana_) currentMana_ = maxMana_;

        std::cout << name_ << " 回复了 "
                  << amount << " 点魔力，剩余魔力："
                  << currentMana_ << std::endl;
    }

    // 打印当前状态
    void printStatus() const {
        std::cout << name_
                  << " | HP: " << currentHp_
                  << " | Mana: " << currentMana_
                  << std::endl;
    }

    void setMaxHp(int newMaxHp) {
        if (newMaxHp > 0) {
            maxHp_ = newMaxHp;
            if (currentHp_ > maxHp_) currentHp_ = maxHp_;
        }
    }

    void setMaxMana(double newMaxMana) {
        if (newMaxMana > 0) {
            maxMana_ = newMaxMana;
            if (currentMana_ > maxMana_) currentMana_ = maxMana_;
        }
    }

    bool isAlive() const {
        return currentHp_ > 0;
    }

    int getHp() const { return currentHp_; }
    double getMana() const { return currentMana_; }
    const std::string& getName() const { return name_; }
};

#endif