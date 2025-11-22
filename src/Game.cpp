#include "Game.h"
#include <iostream>
#include <cctype>
#include <limits>

#include "Player.h"
#include "NPC.h"
#include "Item.h"
#include "Enemy.h"
#include "Map.h"
#include "Character.h"
#include "Inventory.h"
Game::Game()
    : player("Goblin Slayer", 100, 20, 100, 0),//why doesn't reduce damage when player got damaged
      gameMap(10, 10, &player),
      running(true), enemiesDefeated(0) {
    std::cout << "Welcome to the RPG!\n";
    Item sword("Iron Sword", 1, WEAPON, 15, 0);
    Item armor("Iron Armor", 1, PROTECT_GEAR, 0, 5);
    player += sword;
    player += armor;

    //create enemies and set their positions
    auto *goblin = new Enemy("Goblin", 100, 100, 8, 2, 25, 'G' );
    goblin->setPosition(4,3);
    enemies.push_back(goblin);

    auto *orc = new Enemy("Orc", 50, 50, 12, 5, 40, 'O' );
    orc->setPosition(3,4);
    enemies.push_back(orc);

    //create NPCs and set their positions
    std::vector<std::string> merchantDialogue = {
        "Welcome, traveler!",
        "There is nothing to buy yet",
        "Please come back when there is final update release",
        "Fack u, I said there is nothing here"
    };

    auto merchant = new NPC("Merchant", merchantDialogue);
    merchant->setPosition(1,2);
    npcs.push_back(merchant);

    std::cout << "Welcome to the RPG!\n";
}
Game::~Game() {
    for (Enemy* e : enemies) {
        delete e;
    } enemies.clear();

    for (const NPC* n : npcs) {
        delete n;
    } npcs.clear();
}

void Game::processInput() {
    char input;
    std::cout << "Move (WASD) or Q to quit, e to interact with NPC: ";
    std::cin >> input;

    int X = player.getX();
    int Y = player.getY();

    if (input == 'W' || input == 'w') Y--;
    else if (input == 'S' || input == 's') Y++;
    else if (input == 'A' || input == 'a') X--;
    else if (input == 'D' || input == 'd') X++;
    else if (input == 'Q' || input == 'q') { running = false; return; }
    else if (input == 'E' || input == 'e') {

        // Talk to NPC on same tile (no movement)
        for (NPC* npc : npcs) {
            if (npc->getX() == player.getX()
                && npc->getY() == player.getY()) {
                interactWithNPC(npc);
                waitForKey();
                return;
                }
        }
        return; // no NPC, do nothing
    }
    else if (input == 'I' || input == 'i') {
        Inventory inventory;
        inventory.display();
    }
    else return;

    if (gameMap.isWall(X, Y))
        return;

    player.setPosition(X, Y);

    for (Enemy* enemy : enemies) {
        if (enemy->isAlive()
            && enemy->getX() == X
            && enemy->getY() == Y)
        {
            combat(enemy);
            return;
        }
    }
    }

bool Game::combat(Enemy *enemy) {
    if (!enemy) {
        std::cout << "[DEBUG] combat called with null enemy\n";
        return false;
    }

    std::cout << "\n=== Combat Started! ===\n";
    std::cout << "You encounter a " << enemy->getName() << "!\n";
    while (player.isAlive() && enemy->isAlive()) {
        int playerDamage = player.getAttackPower();
        int choice;

        std::cout << "1 to attack, 2 to quit combat \n" << "Your turn: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "You cast testicular torsion on ";
                enemy->takeDamage(playerDamage);
                std::cout << "actual damage: " << playerDamage << " damage.\n";
                break;
            case 2:
                return true;
            default:
                std::cout << "invalid choice";
                continue;
        }

        if (!enemy->isAlive()) {
            std::cout << "You defeated the " << enemy->getName() << "!\n";
            player.gainExp(enemy->getExpReward());
            enemiesDefeated++;
            return true;
        }
        // the first problem , I use inheritance from Character so it only reduce in  player("Goblin Slayer", 100, 20, 100, 0) instead of my Protect gear.
        // the second is here in while combat, I make damage from enemies directly on player health instead of through armor
        int enemyDamage = enemy->getAttackPower();
        int beforeHP = player.getHealth();
        player.takeDamage(enemyDamage);
        int lost =beforeHP - player.getHealth();
        std::cout << enemy->getName() << " turn:\n";
        std::cout << enemy->getName()
                  << " original damage: " << enemyDamage << " damage.\n"
                  << " after reduce damage: " << lost << "damage. \n" ;


        if (!player.isAlive()) {
            std::cout << "You were defeated!\n";
            running = false;
            return false;
        }
    }

    return true;
}

void Game::interactWithNPC(NPC *npc) {
    std::cout << "\n=== Talking to NPC ===\n";
    std::cout << npc->getName() << ":\n";
    npc->speak();
}

void Game::run() {
    while (running) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        gameMap.draw(enemies, npcs); // Pass character vector
        //show status
        std::cout << "\n";
        player.displayStatus();
        std::cout << "Enemies defeated " << enemiesDefeated << "/" << enemies.size() << "\n";

        //process input
        processInput();

        //check win condition
        if (enemiesDefeated >= static_cast<int>(enemies.size())) {
            std::cout << "\n=== VICTORY ===\n";
            running = false;
        }
    }
}
void Game::waitForKey() {
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

