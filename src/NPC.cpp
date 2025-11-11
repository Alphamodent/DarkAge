//
// Created by Seneca on 11/8/2025.
//
#include "NPC.h"
#include <iostream>
#include <sstream>
#include <vector>

NPC::NPC(std::string name, const std::vector<std::string> &dialogueLines)
    : Character(name, 50, 50, 0, 0), dialogue(dialogueLines), currentDialogue(0) {
    std::cout << "NPC " << this->name << " is here" << std::endl;
}

int NPC::getAttackPower() const {
    return 0;
}

void NPC::displayStatus() const {
    std::cout << "NPC: " << name
              << " (Dialogue #" << currentDialogue << ")" << std::endl ;
}

void NPC::speak() {
    if (dialogue.empty()) {
        std::cout << name <<" has nothing to say."<<std::endl;
        return;
    }

    // Print current dialogue line
    std::cout << name << ": " << dialogue[currentDialogue] << std::endl;

    // Advance to the next line - cycle back to start if at the end
    currentDialogue = (currentDialogue+1) % dialogue.size();

}

void NPC::addDialogue(const std::string &line) {
    dialogue.push_back(line);
}
