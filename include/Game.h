#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Player.h"

class Game {
private:
    Player player;
    Map gameMap;
    bool running;

    void processInput();

public:
    Game();
    ~Game();

    void run();
};

#endif
