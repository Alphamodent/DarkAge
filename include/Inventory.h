//
// Created by Seneca on 11/1/2025.
//

#ifndef DARK_AGE_INVENTORY_H
#define DARK_AGE_INVENTORY_H

#include "Item.h"
#include <iostream>
#include <string>

class Inventory {
private:
    int capacity;
    int itemCount;
    Item* items;
    std::string name;

public:
    //constructor
    explicit Inventory(int capacity = 5);
    ~Inventory();

    Inventory(const Inventory& other); // copy constructor

    bool addItem(const Item& item);
    void display() const;

    int getTotalAttackBonus() const;
    int getTotalDefenseBonus() const;
};


#endif //DARK_AGE_INVENTORY_H
