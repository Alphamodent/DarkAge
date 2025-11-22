#include "Game.h"
#include <iostream>

int main(){
    Game game;
    std::cout << "Choose 1 to play, 2 to quit \n";
    int option;
    std::cin >> option;

    switch (option) {
        case 1:
            std::cout << "Welcome to Dark Age " << std::endl;
            game.run();
            break;
        case 2:
            std::cout << "Quit Game" << std::endl;
            break;
        default: std::cout << "Invalid choice\n";
    }

    // Game ends
    std::cout << "\nGame Over. Thanks for playing!\n";
    return 0;
}
