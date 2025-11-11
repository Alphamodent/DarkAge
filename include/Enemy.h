//
// Created by Seneca on 11/8/2025.
//

#ifndef DARK_AGE_ENEMY_H
#define DARK_AGE_ENEMY_H
#include "Character.h"

class Enemy : public Character {
protected:
    int expReward; //kill enemy to earn reward
    char symbol; //symbol to appear on map

public:
    //constructor
    Enemy(const std::string& name, int health, int maxHealth, int strength, int armor, int ExpReward, char Symbol);
    ~Enemy() override;

    //get attack damage and blocking mechanic
    void takeDamage(int damage) override;
    int getAttackPower() const override;

    //getter
    char getSymbol() const;
    int getExpReward() const;

    //display status
    void displayStatus() const override;
};


#endif //DARK_AGE_ENEMY_H