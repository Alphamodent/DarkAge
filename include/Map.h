//
// Created by Seneca on 11/1/2025.
//

#ifndef DARK_AGE_MAO_H
#define DARK_AGE_MAO_H

#include "Player.h"
#include <iostream>
#include <vector>
#include "NPC.h"
#include "Enemy.h"

class Map {
private:
    char** grid;
    int width;
    int height;
    Player* player;

public:
    Map(int w, int h, Player* p);
    ~Map();

    //draw() now takes character lists to display
    void draw(const std::vector<Enemy*> &enemies, const std::vector<NPC*> &npcs) const;
    bool isWall(int x, int y) const;

    //Getter method
    int getWidth() const {return width;}
    int getHeight() const {return height;}
};
#endif //DARK_AGE_MAO_H