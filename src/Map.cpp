#include "Map.h"
#include "Player.h"
#include <iostream>
#include <sstream>

Map::Map(int w, int h, Player* p)
    : width(w), height(h), player(p) {
    this->width = w;
    this->height = h;
    this->player = p;

    // allocate rows
    grid = new char*[height];
    for (int i = 0; i < height; i++)
        grid[i] = new char[width];

    // initialize map
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (r == 0 || c == 0 || r == height - 1 || c == width - 1)
                grid[r][c] = '#';
            else
                grid[r][c] = '.';
        }
    }

    // set player start position
    player->setPosition(1, 1);
}

Map::~Map() {
    for (int i = 0; i < height; i++)
        delete[] grid[i];
    delete[] grid;
}

void Map::draw() const {
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (r == player->getY() && c == player->getX())
                std::cout << '@';
            else
                std::cout << grid[r][c];
        }
        std::cout << '\n';
    }
}

bool Map::isWall(int x, int y) const {
    if (x < 0 || y < 0 || x >= width || y >= height)
        return true; // out of bounds
    return grid[y][x] == '#';
}
