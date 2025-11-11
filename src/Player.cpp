//
// Created by Seneca on 11/1/2025.
//

#include "Player.h"
#include "Item.h"
#include <iostream>
#include <string>

Player::Player(std::string name, int health, int strength, int maxHealth, int armor)
    : Character(std::move(name), health, maxHealth, strength, armor ){
}

Player::~Player() {
    std::cout << "Player " << name <<" has left the game \n" << std::endl;
}

int Player::getAttackPower() const {
    int totalAttack = strength;
    totalAttack += inventory.getTotalAttackBonus();
    return totalAttack;
}

void Player::takeDamage(int damage) {
    Character::takeDamage(damage);
    if (!isAlive()) {
        displayStatus();
        std::cout << "Game Over! "<<name<<" has fallen" << std::endl;
    }
}

void Player::levelUp() {
    ++level;
    maxHealth += 10;
    strength += 2;
    health = maxHealth;
    expToNextLevel = level *50;
    std::cout << "LEVEL UP! [" << name << "] is now level" << level <<"\n";
    std::cout << " maxHealth = " << maxHealth << "\n Attack power: " << strength << "\n health: " << health << "\n";
}

void Player::showInventory() const {
    inventory.display();
}

Player & Player::operator+=(const Item &item) {
    if (inventory.addItem(item)) {
        std::cout << name << " found a " << item << std::endl;
    } else {
        std::cout << name << "'s inventory is full! Could not add " << item << std::endl;
    }
    return *this;
}

void Player::gainExp(int exp) {
    std::cout << "[" << name << "] gains [" << exp << "] EXP! \n";
    experience += exp;
    if (experience >= expToNextLevel) {
        experience -= expToNextLevel;
        levelUp();
    }
}