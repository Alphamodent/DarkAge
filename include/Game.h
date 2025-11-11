#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Player.h"

class Game {
private:
    Player player;
    Map gameMap;

    std::vector<Enemy*> enemies;
    std::vector<NPC*> npcs;

    bool running;
    int enemiesDefeated;
    Item item;

public:
    Game();
    ~Game();
    void run();

    static void waitForKey();
    //helper methods
    void processInput();
    bool combat(Enemy* enemy);
    static void interactWithNPC(NPC* npc);

};

#endif
