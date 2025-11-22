//
// Created by Seneca on 11/1/2025.
//
#include "Item.h"
#include <string>

int Item::totalItems = 0;

static const char* toString(ItemType t) {
    switch (t) {
        case WEAPON:       return "Weapon";
        case PROTECT_GEAR: return "Protection Gear";
        default:           return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getName()
        << " | type= " << toString(item.getType())
        << " | value= " << item.getValue();

    // Print the relevant stat depending on type
    if (item.getType() == WEAPON) {
        out << " | atk= " << item.getAttackBonus();
    } else if (item.getType() == PROTECT_GEAR) {
        out << " | def= " << item.getArmorBonus();
    }
    return out;
}
Item::Item(): name(" "), strengthPower(0), protectionPower(0), value(0), type(){}

Item::Item(const std::string& name, const int value, const ItemType type, const int AttackPower, const int armor)
    : name(name), value(value), type(type), strengthPower(AttackPower), protectionPower(armor) {
    this->name = name;
    this->value = value;
    if (type == WEAPON)
        strengthPower = AttackPower;
    else if (type == PROTECT_GEAR)
        protectionPower = armor;

    totalItems++;
}

