//
// Created by Seneca on 11/1/2025.
//
#pragma once
#ifndef DARK_AGE_ITEM_H
#define DARK_AGE_ITEM_H

#include <iostream>
#include <string>
enum ItemType{PROTECT_GEAR, WEAPON};

class Item {
private:
    std::string name;
    int strengthPower; //add to player's strength by weapon
    int protectionPower; //add to player's armor by protection gear
    static int totalItems; //count total item in inventory and declare limit item that player can hold
    int value; // 1 item = 1 value, exp: inventory(0/10) -> mean player can hold 10 items
    ItemType type; // only PROTECT GEAR and WEAPON first, consumable will be added later

public:
    //constructor
    Item();
    Item(const std::string& name, int value, ItemType type, int power);

    //Getter methods
    std::string getName() const{return name;}
    int getValue() const{return value;}
    ItemType getType() const{return type;}
    int getAttackBonus() const {return strengthPower;}
    int getArmorBonus() const {return protectionPower;}

    //Static method
    static int getTotalItems() {return totalItems;}

    //Friend function
    friend std::ostream& operator<<(std::ostream& out, const Item& item);

};
#endif //DARK_AGE_ITEM_H
