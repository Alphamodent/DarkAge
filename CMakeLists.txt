cmake_minimum_required(VERSION 3.10)
project(Dark_age)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Headers live here for both targets
include_directories(include)

add_executable(Dark_age
        src/main.cpp
        src/Game.cpp
        src/Map.cpp
        src/Player.cpp
        src/Character.cpp
        src/Inventory.cpp
        src/Item.cpp
)


enable_testing()

add_executable(rpg_tests
        tests/Test.cpp        # my test file with its own main()
        src/Character.cpp
        src/Inventory.cpp
        src/Item.cpp
        src/Map.cpp
        src/Player.cpp
)

add_test(NAME rpg_tests COMMAND rpg_tests)
