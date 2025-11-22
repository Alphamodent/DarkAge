// test3.cpp
#include <iostream>     // needed before Player.h because of inline displayStatus()
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

void printPlayerState(const Player& p, const std::string& label) {
    std::cout << "=== " << label << " ===\n";
    p.displayStatus();
    std::cout << "\nArmor power:  " << p.getArmorPower()
              << "\nAttack power: " << p.getAttackPower()
              << "\nLevel: " << p.getLevel()
              << "  EXP: " << p.getExp()
              << "\n\n";
}

int main() {
    // Create a test player and an enemy
    Player hero("Tester", 100, 20, 100, 0);           // no base armor
    Enemy  goblin("Goblin", 50, 50, 15, 0, 25, 'G');  // simple enemy

    // ---------- TEST 1: damage with NO armor ----------
    std::cout << "\n[TEST 1] Damage WITHOUT armor\n";
    printPlayerState(hero, "Before hit (no armor)");

    int rawDamage = goblin.getAttackPower();
    std::cout << "Goblin raw damage: " << rawDamage << "\n";

    int beforeHP = hero.getHealth();
    hero.takeDamage(rawDamage);
    int afterHP = hero.getHealth();

    std::cout << "Player HP: " << beforeHP << " -> " << afterHP
              << " (took " << beforeHP - afterHP << " damage)\n\n";

    // ---------- TEST 2: add armor item, then take damage ----------
    std::cout << "\n[TEST 2] Damage WITH armor from inventory\n";

    // PROTECT_GEAR item: value = 10, +0 attack, +5 armor
    Item leatherArmor("Leather Armor", 10, PROTECT_GEAR, 0, 5);
    hero += leatherArmor;   // uses Player::operator+= and Inventory::addItem

    printPlayerState(hero, "After equipping Leather Armor");

    rawDamage = goblin.getAttackPower();
    std::cout << "Goblin raw damage: " << rawDamage << "\n";

    beforeHP = hero.getHealth();
    hero.takeDamage(rawDamage);
    afterHP = hero.getHealth();

    std::cout << "Player HP: " << beforeHP << " -> " << afterHP
              << " (took " << beforeHP - afterHP << " damage)\n\n";

    // ---------- TEST 3: EXP / level up ----------
    std::cout << "\n[TEST 3] Gain EXP and (maybe) level up\n";
    hero.gainExp(100);   // should trigger levelUp if expToNextLevel > 0
    printPlayerState(hero, "After gaining 100 EXP");

    return 0;
}
