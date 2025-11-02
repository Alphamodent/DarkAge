#include <cassert>
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "Map.h"
#include "Player.h"

int main() {
    // -------- Test 1: Normal operation --------
    // Character takes damage; armor reduces it; HP clamps to >= 0.
    // Logic: reduceDamage = damage - armor (floor at 0) then health -= reduceDamage.
    // (See Character::takeDamage implementation in my code.)
    {
        Character c1("Knight", /*health*/20, /*max*/20, /*str*/5, /*armor*/3);
        c1.takeDamage(7);                 // 7-3 = 4
        assert(c1.getHealth() == 16);     // 20 - 4 = 16
        assert(c1.isAlive());             // still alive
    }

    // -------- Test 2: Edge case --------
    // Inventory with capacity 0 cannot accept items; totals on empty bag are zero.
    {
        Inventory inv(0);
        Item dagger("Dagger", 1, WEAPON, 2);
        bool added = inv.addItem(dagger);      // should fail at capacity check
        assert(added == false);

        // Empty inventory totals are zero
        assert(inv.getTotalAttackBonus()  == 0);
        assert(inv.getTotalDefenseBonus() == 0);
    }

    // -------- Test 3: Boundary conditions --------
    // Map builds a wall border and treats out-of-bounds as wall.
    // Player spawns at (1,1) inside the walkable area.
    {
        Player p("Hero", 100, 10, 100, 0);
        Map m(10, 5, &p);

        // Spawn point inside the map and not a wall
        assert(p.getX() == 1 && p.getY() == 1);
        assert(m.isWall(1, 1) == false);

        // Border tiles are walls
        assert(m.isWall(0, 0)  == true);
        assert(m.isWall(9, 0)  == true);
        assert(m.isWall(0, 4)  == true);
        assert(m.isWall(9, 4)  == true);

        // Out-of-bounds counts as wall
        assert(m.isWall(-1, 2) == true);
        assert(m.isWall(10, 2) == true);
        assert(m.isWall(2, -1) == true);
        assert(m.isWall(2,  5) == true);
    }

    return 0;
}
