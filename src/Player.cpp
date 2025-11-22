//
// Created by Seneca on 11/1/2025.
//

#include "Player.h"
#include "Item.h"
#include <iostream>
#include <string>
#include "Inventory.h"
#include "Character.h"

Player::Player(std::string name, int health, int strength, int maxHealth, int armor)
    : Character(std::move(name), health, maxHealth, strength, armor ),
     inventory(5)
    {
    level = 1;
    experience = 0;
    expToNextLevel = 50;
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
    // the first problem is here, I use inheritance from Character so it only reduce in  player("Goblin Slayer", 100, 20, 100, 0) instead of my Protect gear.
    // the second is in while combat, I make damage from enemies directly on player health instead of through armor
    int effectiveArmor = getArmorPower();
    int reducedDamage = damage - effectiveArmor;
    if (reducedDamage < 0) reducedDamage = 0;

    health -= reducedDamage;
    if (health < 0) health = 0;

    if (!isAlive()) {
        displayStatus();
        std::cout << "Game Over! "<<name<<" has fallen" << std::endl;
    }
}
int Player::getArmorPower() const {
    int totalArmor = armor;
    totalArmor += inventory.getTotalDefenseBonus();
    return totalArmor;
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