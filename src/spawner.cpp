#include <random>
#include "game_constants.h"
#include "spawner.h"

Spawner::Spawner()
: spawnedThisSecond_{0}
{
}

void Spawner::update()
{
    if (timer_.getElapsedTime().asSeconds() >= 1) {
        timer_.restart();
        // spawn
    }
}

void Spawner::spawn()
{
    if (spawnedThisSecond_ < APPLES_PER_SECOND) {
        ++spawnedThisSecond_;
    }
}
