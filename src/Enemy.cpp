//
// Created by Seneca on 11/8/2025.
//
#include "Enemy.h"

#include <utility>

Enemy::Enemy(const std::string& name, int health, int maxHealth, int strength, int armor, int ExpReward, char Symbol)
    : Character(name, health, maxHealth, strength, armor), expReward(ExpReward), symbol(Symbol) {}

Enemy::~Enemy() {
    std::cout << "Enemy [" << name << "] has been defeated" << std::endl;
}

void Enemy::takeDamage(int damage) {
    // 10% chance to block half damage
    if (rand() % 100 < 10) {
        damage /= 2;
        std::cout << name << " blocks some of the damage!" << std::endl;
    }
    Character::takeDamage(damage);
}

int Enemy::getAttackPower() const {
    return Character::getAttackPower();
}

char Enemy::getSymbol() const {
    return symbol;
}

int Enemy::getExpReward() const {
    return expReward;
}

void Enemy::displayStatus() const {
    Character::displayStatus();
}
