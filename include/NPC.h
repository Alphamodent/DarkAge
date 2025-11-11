//
// Created by Seneca on 11/8/2025.
//

#ifndef DARK_AGE_NPC_H
#define DARK_AGE_NPC_H
#include "Character.h"
#include <vector>
#include <iostream>
#include <string>

class NPC: public Character {
protected:
    std::vector<std::string> dialogue;
    int currentDialogue;

public:
    // constructor
    NPC(std::string name, const std::vector<std::string> &dialogueLines);
    ~NPC() override = default;

    //MUST override pure virtual function
    int getAttackPower() const override;
    void displayStatus() const override;

    //NPC-specific method
    void speak();
    void addDialogue(const std::string &line);
};
#endif //DARK_AGE_NPC_H