/**
 * "Orchard" is a dead simple 2D game where the objective is to catch
 * apples as they fall from the treetops above. This project was
 * primarily developed as a way to learn more about game programming
 * and the SFML library.
 *
 * Goals:
 *
 * - Learn more about SFML.
 * - Practice and learn more about game programming.
 * - Apply patterns from "Game Programming Patterns"
 *
 * This project is NOT an attempt at creating a game engine.
 */

#include "engine/game.h"

int main(int argc, char* argv[])
{
    Game g("Orchard");
    g.run();
    return 0;
}

