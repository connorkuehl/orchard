#ifndef ORCHARD_SPAWNER_H
#define ORCHARD_SPAWNER_H

#include <vector>
#include "apple.h"

namespace
{
    const auto DEFAULT_SPAWN_DELAY = 1.75f;
}

/**
 * @brief The Spawner class is responsible for spawning Apples for the Player to catch.
 */
class Spawner : public virtual sf::Drawable
{
    public:
        /// @brief Constructs the Spawner and sets the initial spawn delay.
        explicit Spawner(float initialSpawnDelay = DEFAULT_SPAWN_DELAY);
        /// @brief Provides a prototype Apple for the spawner to clone.
        void attachPrototype(Apple &prototype);
        /// @brief Queries if any of the spawner's objects are colliding with the one passed in.
        bool isSpawnCollidingWith(const GameObject &other);
        /// @brief Updates the Spawner and all of its spawns.
        void update(float elapsed);
        /// @brief Draws all of the Spawner's active spawns.
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    private:
        Apple prototype_; ///< The Apple of which all spawns will be cloned from.
        sf::Clock timer_; ///< The Spawner's timer to know when to spawn a new Apple.
        std::vector<Apple> apples_; ///< The Apples managed by the Spawner.
        float spawnDelay_; ///< The delay (difficulty) that the Spawner must wait before spawning more Apples.

        void spawn(); ///< Spawns an Apple at a random position falling from the top of the Scene.
        sf::Vector2f randomPosition() const; ///< Generates a random X coordinate (the Y is fixed to the top).
};

#endif //ORCHARD_SPAWNER_H
