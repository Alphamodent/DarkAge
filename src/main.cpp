#include "Game.h"
#include <iostream>

int main() {
    std::cout << "Starting game...\n";
    Game game;
    game.run();

    // Game ends
    std::cout << "\nGame Over. Thanks for playing!\n";
    return 0;
}
