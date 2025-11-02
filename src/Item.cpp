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
    out << "[Item] "
        << item.getName()
        << " | type=" << toString(item.getType())
        << " | value=" << item.getValue();

    // Print the relevant stat depending on type
    if (item.getType() == WEAPON) {
        out << " | atk=" << item.getAttackBonus();
    } else if (item.getType() == PROTECT_GEAR) {
        out << " | def=" << item.getAttackBonus();
    }
    return out;
}
Item::Item(): name(" "), strengthPower(0), protectionPower(0), value(0), type(){
}

Item::Item(std::string name, int value, ItemType type, int power)
    : name(name), value(value), type(type), strengthPower(0), protectionPower(0) {
    this->name = name;
    this->value = value;
    if (type == WEAPON)
        strengthPower = power;
    else if (type == PROTECT_GEAR)
        protectionPower = power;

    totalItems++;
}

