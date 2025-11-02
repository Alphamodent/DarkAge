//
// Created by Seneca on 11/1/2025.
//

#ifndef DARK_AGE_CHARACTER_H
#define DARK_AGE_CHARACTER_H
#include <string>
#include "Item.h"

class Character {
protected:
    std::string name;
    int health{};
    int maxHealth{}; // this is const health and unchangeable to represent for initial health
    int strength{}; // mean base attack power before wear sword to add more damage
    int armor{}; /* same strength and add more protection but will initial with 0
    exp: health = health + armor - damage, armor will not be decrease and const so everytime take damage armor will help health decrease damage*/
    int x, y; //position

public:
    //base constructor
    Character(std::string name, int health, int maxHealth, int strength, int armor);
    virtual ~Character();

    //Combat methods
    virtual void takeDamage(int damage);
    virtual int getAttackPower() const;

    //status method
    bool isAlive() const;
    virtual void displayStatus() const;


    //Position method
    void setPosition(int x,int y);
    int getX() const;
    int getY() const;

    //Getter
    int getHealth() const;
    std::string getName() const;
    int getMaxHealth() const;
};

#endif //DARK_AGE_CHARACTER_H
