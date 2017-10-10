#include <random>
#include <algorithm>
#include <SFML/Graphics/RenderTarget.hpp>
#include "game_constants.h"
#include "spawner.h"

/**
 * Constructs the Spawner and sets the initial spawn delay.
 * @param initialSpawnDelay How long the spawner should wait before spawning another object.
 */
Spawner::Spawner(float initialSpawnDelay)
: prototype_{{0, 0}}
, spawnDelay_{initialSpawnDelay}
{
}

/**
 * Attaches the prototype object for the Spawner to make copies of. This must be called before the Spawner can Spawn
 * anything.
 * @param prototype The object to be spawned repetetively.
 */
void Spawner::attachPrototype(Apple &prototype)
{
    prototype_ = prototype;
}

/**
 * Queries if the other game object is colliding with any of the spawner's spawns.
 * @param other The GameObject to test collisions against.
 * @return True if the other object is colliding with a spawn.
 */
bool Spawner::isSpawnCollidingWith(const GameObject &other){
    bool colliding = false;
    for (auto &apple : apples_) {
        if (apple.isCollidingWith(other)) {
            apple.die();
            colliding = true;
        }
    }
    return colliding;
}

/**
 * Updates the Spawner's game logic. Destroys objects that have been collided with or are off-screen. Updates all
 * spawns.
 * @param elapsed The elapsed time for this iteration of the game loop.
 */
void Spawner::update(float elapsed)
{
    if (timer_.getElapsedTime().asSeconds() >= spawnDelay_) {
        spawn();
        timer_.restart();
    }

    for (auto &apple : apples_) {
        apple.update(elapsed);
    }

    apples_.erase(std::remove_if(apples_.begin(), apples_.end(),
    [](const auto &apple) {
        return apple.isDead();
    }), apples_.end());
}

/**
 * Draws the Spawner's spawns to the window.
 */
void Spawner::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto &apple : apples_) {
        target.draw(apple);
    }
}

/**
 * Spawns an Apple at a random location. The Y position is fixed; however, because the apples must fall
 * from the top of the screen.
 */
void Spawner::spawn()
{
    apples_.emplace_back(prototype_.clone(randomPosition()));
}

/**
 * @return A random X position (with the Y coordinate fixed to the top of the screen).
 */
sf::Vector2f Spawner::randomPosition() const
{
    static std::default_random_engine engine{};
    static std::uniform_real_distribution<float> range{0, game::SCREEN_WIDTH - 32};
    return {range(engine), 0.f};
}
