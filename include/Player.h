//
// Created by Seneca on 11/1/2025.
//

#ifndef DARK_AGE_PLAYER_H
#define DARK_AGE_PLAYER_H
#include <cmath>
#include "Character.h"
#include "Inventory.h"

class Player : public Character {  // Now inherits from Character!
private:
    Inventory inventory;
    int level{};
    int experience{};
    int expToNextLevel{};

public:
    // Constructor - note different parameters than before
    Player(std::string name, int health, int strength, int maxHealth, int armor);

    // Destructor
    ~Player() override;

    // MUST override pure virtual function from Character (required!)
    int getAttackPower() const override;

    // Override from Character (redefine for player-specific behavior)    void takeDamage(int damage);  // Redefine to show player-specific message
    void takeDamage(int damage) override;

    // Optional override (base class has implementation)
    void displayStatus() const override {
        std::cout << name << " - HP: [" << health << "]/[" <<maxHealth << "]";
    }

    // Leveling system
    void levelUp();

    // Inventory access
    void showInventory() const;
    Player& operator+=(const Item& item);

    // Getters
    int getLevel() const {return level;}
    int getExp() const {return experience;}

    void gainExp(int exp);
};


#endif //DARK_AGE_PLAYER_H
