//
// Created by Seneca on 11/1/2025.
//
#include "Inventory.h"
#include "Item.h"
#include <iostream>

Inventory::Inventory(int capacity): capacity(capacity), itemCount(0) {
    items = new Item[capacity];
}

Inventory::~Inventory() {
    delete[] items;
}

Inventory::Inventory(const Inventory &other) : capacity(other.capacity), itemCount(other.itemCount) {
    items = new Item[capacity];     // allocate new array
    for (int i = 0; i < itemCount; i++) {
        items[i] = other.items[i]; // deep copy
    }
}

bool Inventory::addItem(const Item &item) {
    if (itemCount < capacity) {
        items[itemCount++] = item; //assignment
        return true;
    }
    return false;
}

void Inventory::display() const {
    std::cout << "Inventory (" << itemCount << "/" << capacity << "): " << std::endl;
    for (int i = 0; i < itemCount; i++) {
        std::cout << " " << items[i] << std::endl;
    }
}

int Inventory::getTotalAttackBonus() const {
    int total =0;
    for (int i =0; i <itemCount-1; i++) {
        if (items[i].getType() == WEAPON) {
            total += items[i].getAttackBonus();
        }
    }
    return total;
}

int Inventory::getTotalDefenseBonus() const {
    int total = 0;
    for (int i =0; i <itemCount-1; i++) {
        if (items[i].getType() == PROTECT_GEAR) {
            total += items[i].getAttackBonus();
        }
    }
    return total;
}
// haiyaa I just remember that I try to use getAttackBonus for bonus Attack and Defend for reusable (I'm lazy).