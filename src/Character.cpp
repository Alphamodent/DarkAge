//
// Created by Seneca on 11/1/2025.
//
#include "Character.h"
#include "Game.h"
#include <iostream>
#include "Item.h"

Character::Character(std::string name, int health, int maxHealth, int strength, int armor)
    :name(std::move(name)), health(health), maxHealth(maxHealth), strength(strength), armor(armor), y(0), x(0) {
    this->maxHealth = maxHealth;
    this->name = std::move(name);
}

Character::~Character() {
    std::cout << "Character "<<this->name<<" had been destroyed" << std::endl;
}

void Character::takeDamage(int damage) {
    int reduceDamage = damage - armor;
    if (reduceDamage < 0) reduceDamage = 0;

    health -= reduceDamage;
    std::cout << "[" << name << "] takes [" << reduceDamage <<"] damage! \n";
    if (health < 0) health=0;
}

int Character::getAttackPower() const { return strength;}

bool Character::isAlive() const {
    if (health > 0) return true;
    return false;
}

void Character::displayStatus() const {
    std::cout << name << " - HP: [" << health << "]/[" <<maxHealth << "]";
}

void Character::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

int Character::getX() const {return x;}
int Character::getY() const {return y;}

int Character::getHealth() const {return health;}
std::string Character::getName() const {return name;}
int Character::getMaxHealth() const {return maxHealth;}