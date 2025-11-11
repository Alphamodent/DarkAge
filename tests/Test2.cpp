// Test.cpp
#include <iostream>
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Inventory.h"
#include "NPC.h"
#include "Map.h"

// Simple test macro
#define CHECK(cond, msg) \
    do { \
        if (cond) std::cout << "[PASS] " << msg << "\n"; \
        else      std::cout << "[FAIL] " << msg << "\n"; \
    } while (0)

void testCharacterBasics() {
    std::cout << "\n=== testCharacterBasics ===\n";
    Character c("TestChar", 50, 50, 10, 2);

    CHECK(c.getName() == "TestChar", "Character name");
    CHECK(c.getHealth() == 50, "Character initial HP");
    CHECK(c.getMaxHealth() == 50, "Character max HP");
    CHECK(c.getAttackPower() == 10, "Character attack power");
    CHECK(c.isAlive(), "Character alive at start");

    c.setPosition(3, 4);
    CHECK(c.getX() == 3 && c.getY() == 4, "Character position set/get");

    c.takeDamage(5); // armor=2 → damage taken = 3
    CHECK(c.getHealth() == 47, "Character damage with armor");

    c.takeDamage(1000);
    CHECK(c.getHealth() == 0, "Character HP not below 0");
    CHECK(!c.isAlive(), "Character dead when HP=0");
}

void testItemAndInventory() {
    std::cout << "\n=== testItemAndInventory ===\n";

    Inventory inv(5);

    Item sword("Test Sword", 10, WEAPON, 5);
    Item armor("Test Armor", 15, PROTECT_GEAR, 3);

    CHECK(inv.addItem(sword), "Add weapon to inventory");
    CHECK(inv.addItem(armor), "Add armor to inventory");

    int atkBonus = inv.getTotalAttackBonus();
    int defBonus = inv.getTotalDefenseBonus();

    std::cout << "Attack bonus = " << atkBonus << "\n";
    std::cout << "Defense bonus = " << defBonus << "\n";

    CHECK(atkBonus >= 5, "Inventory attack bonus (>= sword bonus)");
    CHECK(defBonus >= 3, "Inventory defense bonus (>= armor bonus)");
}

void testPlayer() {
    std::cout << "\n=== testPlayer ===\n";

    Player p("Hero", 100, 20, 100, 5); // (name, health, strength, maxHealth, armor)

    CHECK(p.getName() == "Hero", "Player name");
    CHECK(p.getHealth() == 100, "Player HP");
    CHECK(p.getAttackPower() >= 20, "Player base attack >= 20");

    Item sword("Iron Sword", 10, WEAPON, 5);
    p += sword;

    int atk = p.getAttackPower();
    std::cout << "Player attack after sword = " << atk << "\n";
    CHECK(atk >= 25, "Player attack increased by weapon");

    p.takeDamage(10); // goes through Character::takeDamage (armor applied)
    CHECK(p.getHealth() <= 100 && p.getHealth() > 0, "Player took damage safely");

    p.gainExp(1000); // should level up at least once
}

void testEnemy() {
    std::cout << "\n=== testEnemy ===\n";

    Enemy e("Goblin", 30, 30, 8, 1, 25, 'G');
    e.setPosition(4, 3);

    CHECK(e.getName() == "Goblin", "Enemy name");
    CHECK(e.getHealth() == 30, "Enemy HP");
    CHECK(e.getAttackPower() == 8, "Enemy attack");
    CHECK(e.getSymbol() == 'G', "Enemy symbol");
    CHECK(e.getExpReward() == 25, "Enemy exp reward");

    // Test damage once (not relying on block chance)
    e.takeDamage(5); // armor=1 → effective 4, unless block triggers
    CHECK(e.getHealth() <= 30 && e.getHealth() >= 0, "Enemy takes damage safely");
}

void testNPC() {
    std::cout << "\n=== testNPC ===\n";

    std::vector<std::string> lines = {
        "Hello!",
        "Need something?",
        "Goodbye."
    };

    NPC npc("Merchant", lines);
    npc.setPosition(2, 2);

    CHECK(npc.getName() == "Merchant", "NPC name");
    CHECK(npc.getX() == 2 && npc.getY() == 2, "NPC position");

    std::cout << "NPC speak test:\n";
    npc.speak();
    npc.speak();
    npc.speak();
}

void testMapAndCollision() {
    std::cout << "\n=== testMapAndCollision ===\n";

    Player p("Tester", 100, 10, 100, 2);
    Map map(10, 10, &p); // sets player at (1,1)

    CHECK(map.isWall(0, 0), "Corner is wall");
    CHECK(!map.isWall(1, 1), "Inside is floor");

    // One enemy & one NPC to verify drawing / positions
    Enemy* goblin = new Enemy("Goblin", 30, 30, 8, 1, 25, 'G');
    goblin->setPosition(4, 3);

    std::vector<Enemy*> enemies{ goblin };

    std::vector<std::string> d = {"Hi"};
    NPC* merchant = new NPC("Merchant", d);
    merchant->setPosition(2, 2);
    std::vector<NPC*> npcs{ merchant };

    std::cout << "Map draw test:\n";
    map.draw(enemies, npcs);

    delete goblin;
    delete merchant;
}

void testSimpleCombatLikeFlow() {
    std::cout << "\n=== testSimpleCombatLikeFlow ===\n";

    // Minimal manual combat test without Game::run()
    Player player("Hero", 100, 20, 100, 5);
    Enemy enemy("Goblin", 30, 30, 8, 1, 25, 'G');

    std::cout << "Start: Hero HP=" << player.getHealth()
              << " Goblin HP=" << enemy.getHealth() << "\n";

    while (player.isAlive() && enemy.isAlive()) {
        int playerDmg = player.getAttackPower();
        enemy.takeDamage(playerDmg);

        if (!enemy.isAlive()) {
            std::cout << "Goblin defeated!\n";
            break;
        }

        int enemyDmg = enemy.getAttackPower();
        player.takeDamage(enemyDmg);
    }

    CHECK(player.isAlive() || !enemy.isAlive(),
          "Combat loop completed without crash");
}

int main() {
    std::cout << "=== RUNNING UNIT TESTS ===\n";

    testCharacterBasics();
    testItemAndInventory();
    testPlayer();
    testEnemy();
    testNPC();
    testMapAndCollision();
    testSimpleCombatLikeFlow();

    std::cout << "\n=== TESTS DONE ===\n";
    return 0;
}
