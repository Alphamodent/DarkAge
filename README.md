# Dark Age
A small, turn-based console RPG where you explore a grid map, battle enemies, manage inventory, and maintain health.

## Features
- New Game & create Character, Enemy, and NPC
- Map Movement (W/A/S/D) with simple world map.
- Inventory: wear armor
- Turn-based combat: adjacent combat attack
- Command line for displaying status or quitting the game
- Enemies disappear when defeated.

## Update

**Implemented Features**:
- ✅ Whoever put invalid choice is GAY
- ✅ Add reduce damage function
- ✅ Add Map, only player on it
- ✅ Add Player and use inheritance from Character
- ✅ Add sword and armor (Protect_gear) in Item
- ✅ Add Inventory and put Item in Inventory
- ✅ Add Test without if-else and add explanations for clarity
- ✅ Add enemy and NPC in map
- ✅ Add interact with NPC
- ✅ Add combat with enemy
- ✅ Add output for combat enemy
- ✅ Add menu: show Start game and quit game
- this is a small update and fix bug

**In Progress**:
- ⏳ Trying to equip and remove sword and armor
- ⏳ Show inventory, health player while combat

**Planned**:
- 📋 Add equip and remove sword and armor
- 📋 Add command-line options to display and show combat actions for characters (e.g., attack, defend, run)

**Known Issues**:
- In friend function, I can’t put it in main.cpp, so I changed implementation to Item.cpp.
- Want to separate Weapon and Protect_gear into different functions.
- The CMake list is now separated between test and run targets, because otherwise it fails when running tests.
- Fixing logic for attaching weapon and protect-gear (harder than expected).
- currently armor gear is not attach to player to help player reduce damage. *need to fix and find problem
- if want to add command line don't have to create other class just create a function.
