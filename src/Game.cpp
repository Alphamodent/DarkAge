#include "Game.h"
#include <iostream>
#include <cctype>

Game::Game()
    : player("Hero", 100, 10, 100, 0),
      gameMap(30, 15, &player),
      running(true) {
    std::cout << "Welcome to the RPG!\n";
    Item sword("Iron Sword", 1, WEAPON, 15);
    Item armor("Iron Armor", 1, PROTECT_GEAR, 5);
    player += sword;
    player += armor;
}
Game::~Game() {
    std::cout << "Goodbye!\n";
}

void Game::processInput() {
    char input;
    std::cout << "Move (WASD) or Q to quit: ";
    std::cin >> input;

    int x = player.getX();
    int y = player.getY();

    if (input == 'W' || input == 'w') {y--;}
    else if (input == 'S' || input == 's') {y++;}
    else if (input == 'A' || input == 'a') {x--;}
    else if (input == 'D' || input == 'd') {x++;}
    else if (input == 'Q' || input == 'q') {running = false;return;}
    else {return;}

    if (!gameMap.isWall(x, y))
        player.setPosition(x, y);
}

void Game::run() {
    while (running) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        gameMap.draw();
        processInput();
    }
}
